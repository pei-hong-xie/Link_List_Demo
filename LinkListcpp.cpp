#include<stdio.h>
#include<stdlib.h>
#include<LinkList.h> // ��������ջ��ͷ�ļ�
#include <cmp.h> // �����ȽϺ�����ͷ�ļ�
#include<Menu.h> // �����˵�������ͷ�ļ�
#include<string.h>
#include <ctype.h>


char buffer[100];
// ��ʼ������ջ
Stack* InitStack_LinkList() {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    if (s == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

// ��ջ����
void push_LinkList(Stack* s, double e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = e;
    newNode->next = s->top;
    s->top = newNode;
}

// ��ջ����
int pop_LinkList(Stack* s) {
    if (s->top == NULL) {
        return 0; // ջΪ�գ���ջʧ��
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return 1; // ��ջ�ɹ�
}

// ��ȡջ��Ԫ��
double GetTop_LinkList(Stack* s) {
    if (s->top != NULL) {
        return s->top->data;
    }
    else {
        printf("ջΪ��\n");
        exit(EXIT_FAILURE);
    }
}

// ���ջ
void Delete_LinkList(Stack* s) {
    while (s->top != NULL) {
        pop_LinkList(s);
    }
    free(s);
}

// ʹ������ջʵ�ֵļ��㺯��
double computer_LinkList(char* buffer) {
    char ch;
    Stack* num = InitStack_LinkList(); // ����ջ
    Stack* ope = InitStack_LinkList(); // ������ջ
    push_LinkList(ope, '='); // ����ջһ���Ⱥ���Ϊ��������

    int q = 1;
    double e, a, b, s;
    char c;

    int index = 0;
    ch = buffer[index]; // ��ʼ�� ch
    while (ch != '\0' && (ch != '=' || GetTop_LinkList(ope) != '=')) { // ֱ�������ַ�����β���ߵȺ��Ҳ�����ջ��ҲΪ�ȺŲŽ���ѭ��
        if (isspace(ch)) { // ���Կհ��ַ�
            index++;
            ch = buffer[index];
            continue;
        }

        if (ch == '(') {
            q = 0; // ���������ţ�q��0
        }
        else if (ch == ')') {
            q = 1; // ���������ţ�q��1
        }
        if (isspace(ch)) { // ����ǿհ��ַ���ֱ�Ӷ�ȡ��һ���ַ�
            index++;
            ch = buffer[index];
            continue;
        }
        else if (isdigit(ch) || ch == '.') { // ���ch�����ֻ�С����
            char cc[20];
            int i = 0;
            while (isdigit(ch) || ch == '.') { // ��ȡ�����ַ���
                cc[i++] = ch;
                index++;
                ch = buffer[index];
            }
            cc[i] = '\0';
            e = atof(cc); // ���ַ�����ת��Ϊ˫���ȸ�����
            push_LinkList(num, e); // ������ջ
            continue;
        }
        else { // ����ǲ�����
            switch (cmp(GetTop_LinkList(ope), ch)) {
            case '<':
                push_LinkList(ope, ch);
                break;
            case '>':
                c = GetTop_LinkList(ope);
                pop_LinkList(ope);
                a = GetTop_LinkList(num);
                pop_LinkList(num);
                b = GetTop_LinkList(num);
                pop_LinkList(num);
                push_LinkList(num, count(a, c, b));
                continue;
            case '=':
                pop_LinkList(ope);
                break;
            }
        }
        index++;
        ch = buffer[index];
    }
    if (ch != '=' && ch != '\n') { // ���벻�ԵȺŻ��з���β����ʾ���������Ϣ����������
        printf("�������: ����δ���\n");
        exit(EXIT_FAILURE);
    }
    s = GetTop_LinkList(num); // ��ȡ������
    pop_LinkList(ope);
    Delete_LinkList(num); // �ͷ��ڴ�
    Delete_LinkList(ope);
    return s; // ���ؼ�����
}
// ��������ջʵ�ֵļ��㺯������������
void Ans_Link_List() {
    printf("��ջʵ��:\n");
    remind(); // ��ʾ�û�������ʽ
    double ans2;
    int index = 0; // ���ڼ�¼�ַ�����ĵ�ǰ����λ��
    // ѭ����ȡÿ���ַ���ֱ���������з���Enter ����
    fgets(buffer, sizeof(buffer), stdin); // �ӱ�׼�����ж�ȡ�ַ���
    ans2 = computer_LinkList(buffer);
    printf("%lf\n", ans2); // ������
    Back_Meun(); // ���ز˵�
}
