#include <stdio.h>
#include <stdlib.h>
#include <SequenceList.h> // ����˳��ջ��ͷ�ļ�
#include <cmp.h> // �����ȽϺ�����ͷ�ļ�
#include <Menu.h> // �����˵�������ͷ�ļ�
#include <ctype.h>


#define  MAX_SIZE 100 // ����ջ���������
extern char buffer[100];
// ��ʼ��˳��ջ
int InitStack_SequenceList(Stack_Se* s) {
    s->base = (double*)malloc(MAX_SIZE * sizeof(double)); // �����ڴ�
    if (!s->base)
        return 0; // �ڴ����ʧ��
    s->top = s->base; // ��ʼ��ջ��ָ��
    s->stacksize = MAX_SIZE; // ջ���������
    return 1; // ��ʼ���ɹ�
}

// ��ջ����
int push_SequenceList(Stack_Se* s, double e) {
    if (s->top - s->base == s->stacksize) // ջ��
        return 0;
    *(s->top++) = e; // Ԫ����ջ
    return 1; // ��ջ�ɹ�
}

// ��ջ����
int pop_SequenceList(Stack_Se* s) {
    if (s->top == s->base) // ջ��
        return 0;
    --(s->top); // ջ��ָ���һ
    return 1; // ��ջ�ɹ�
}

// ��ȡջ��Ԫ��
double GetTop_SequenceList(Stack_Se s) {
    if (s.top != s.base)
        return *(s.top - 1); // ����ջ��Ԫ��
    else {
        printf("����ʽ���󣡣���\n");
        exit(-1); // ջ�գ������˳�
    }
}

// ���ջ
void Delete_SequenceList(Stack_Se* s) {
    free(s->base); // �ͷ��ڴ�
}

// ʹ��˳��ջʵ�ֵļ��㺯��
double Computer_SequenceList(char* buffer) {
    char ch;
    Stack_Se num, ope;
    InitStack_SequenceList(&num); // ��ʼ������ջ
    InitStack_SequenceList(&ope); // ��ʼ��������ջ
    push_SequenceList(&ope, '='); // ����ջһ���Ⱥ���Ϊ��������

    int q = 1;
    double e, a, b, s;
    char c;

    int index = 0;
    ch = buffer[index]; // ��ʼ�� ch
    while (ch != '\0' && (ch != '=' || GetTop_SequenceList(ope) != '=')) { // ֱ�������ַ�����β���ߵȺ��Ҳ�����ջ��ҲΪ�ȺŲŽ���ѭ��
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
            push_SequenceList(&num, e); // ������ջ
            continue;
        }
        else { // ����ǲ�����
            switch (cmp(GetTop_SequenceList(ope), ch)) {
            case '<':
                push_SequenceList(&ope, ch);
                break;
            case '>':
                c = GetTop_SequenceList(ope);
                pop_SequenceList(&ope);
                a = GetTop_SequenceList(num);
                pop_SequenceList(&num);
                b = GetTop_SequenceList(num);
                pop_SequenceList(&num);
                push_SequenceList(&num, count(a, c, b));
                continue;
            case '=':
                pop_SequenceList(&ope);
                break;
            }
        }
        index++;
        ch = buffer[index];
    }
    if (ch != '=' && ch != '\n') { // ���벻�ԵȺŻ��з���β����ʾ���������Ϣ����������
        printf("�������: ����δ���\n");
        return -1;
        //exit(EXIT_FAILURE);
    }
    s = GetTop_SequenceList(num); // ��ȡ������
    pop_SequenceList(&ope);
    Delete_SequenceList(&num); // �ͷ��ڴ�
    Delete_SequenceList(&ope);
    return s; // ���ؼ�����
}

// ����˳��ջʵ�ֵļ��㺯������������
void Ans_SequenceList() {
    remind(); // ��ʾ�û�������ʽ
    double ans1;
    int index = 0; // ���ڼ�¼�ַ�����ĵ�ǰ����λ��
    // ѭ����ȡÿ���ַ���ֱ���������з���Enter ����
    fgets(buffer, sizeof(buffer), stdin); // �ӱ�׼�����ж�ȡ�ַ���
    ans1 = Computer_SequenceList(buffer);
    printf("%lf\n", ans1); // ������
    Back_Meun(); // ���ز˵�
}
