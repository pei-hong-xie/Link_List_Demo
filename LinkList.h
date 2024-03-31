#ifndef __Link_List_H
#define __Link_List_H

// ����һ���ṹ��Node����ʾջ�Ľڵ㣬����һ��double���͵����ݺ�ָ����һ���ڵ��ָ��
typedef struct Node {
    double data;        // �ڵ��д洢������
    struct Node* next; // ָ����һ���ڵ��ָ��
} Node;

// ����һ���ṹ��Stack����ʾջ��ֻ����һ��ָ��ջ���ڵ��ָ��
typedef struct {
    Node* top;  // ָ��ջ���ڵ��ָ��
} Stack;

Stack* InitStack_LinkList();
void push_LinkList(Stack* s, double e);
int pop_LinkList(Stack* s);
double GetTop_LinkList(Stack* s);
void Delete_LinkList(Stack* s);
double computer_LinkList(char* buffer);
void Ans_Link_List();

#endif // !__Link_List_H




