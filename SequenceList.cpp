#include <stdio.h>
#include <stdlib.h>
#include <SequenceList.h> // ����˳��ջ��ͷ�ļ�
#include <cmp.h> // �����ȽϺ�����ͷ�ļ�
#include <Menu.h> // �����˵�������ͷ�ļ�
#define  MAX_SIZE 100 // ����ջ���������

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
double Computer_SequenceList() {
    char ch;
    Stack_Se num, ope;
    InitStack_SequenceList(&num); // ��ʼ������ջ
    InitStack_SequenceList(&ope); // ��ʼ��������ջ
    push_SequenceList(&ope, '='); // ����ջһ���Ⱥ���Ϊ��������

    int q = 1;
    double e, a, b, s;
    char c;

    ch = getchar(); // ��ȡ��һ���ַ�
    while (ch != '=' || GetTop_SequenceList(ope) != '=') { // ֱ�������Ⱥ��Ҳ�����ջ��ҲΪ�ȺŲŽ���ѭ��
        if (ch == '(') {
            q = 0;
        }
        if (ch == ')') {
            q = 1;
        }

        if (In(ch) == 0) { // ���ch�����ֻ�С����
            switch (cmp(GetTop_SequenceList(ope), ch)) { // �Ƚ�ջ���������͵�ǰ�����������ȼ�
            case '<':
                push_SequenceList(&ope, ch); // ��ǰ���������ȼ��ߣ���ջ
                scanf("%c", &ch); // ��ȡ��һ���ַ�
                break;
            case '>':
                c = GetTop_SequenceList(ope); // ջ��������
                pop_SequenceList(&ope); // ��ջ
                a = GetTop_SequenceList(num); // �ڶ���������
                pop_SequenceList(&num); // ��ջ
                b = GetTop_SequenceList(num); // ��һ��������
                pop_SequenceList(&num); // ��ջ
                push_SequenceList(&num, count(a, c, b)); // ��������ջ
                break;
            case '=':
                pop_SequenceList(&ope); // ��ǰ��������ջ�����������ȼ���ȣ���ջ
                scanf("%c", &ch); // ��ȡ��һ���ַ�
                break;
            }
        }
        if ((ch >= '0' && ch <= '9') || ch == '.') { // ���ch�����ֻ�С����
            char cc[20];
            int i;
            for (i = 0; (ch >= '0' && ch <= '9') || ch == '.'; i++) {
                if ((ch >= '0' && ch <= '9') || ch == '.') {
                    cc[i] = ch;
                    scanf("%c", &ch); // ��ȡ��һ���ַ�
                }
            }
            cc[i] = '\0';
            e = atof(cc); // ���ַ�����ת��Ϊ˫���ȸ�����
            push_SequenceList(&num, e); // ������ջ
        }
        if (ch == '=' && q == 0) { // ����Ⱥ�ǰ��δ�պϵ������ţ����ʽ����
            printf("����ʽ���󣡣���\n");
            exit(-1);
        }
    }

    s = GetTop_SequenceList(num); // ��ȡ������
    pop_SequenceList(&ope);
    Delete_SequenceList(&num);
    Delete_SequenceList(&ope);
    return s; // ���ؼ�����
}

// ����˳��ջʵ�ֵļ��㺯������������
void Ans_SequenceList() {
    printf("˳��ջʵ��:\n");
    remind(); // ��ʾ�û�������ʽ
    double ans1;
    ans1 = Computer_SequenceList();
    printf("%lf\n", ans1); // ������
    Back_Meun(); // ���ز˵�
}
