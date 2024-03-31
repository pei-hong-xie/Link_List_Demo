#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include <cmp.h> // �����ȽϺ�����ͷ�ļ�
#include<LinkList.h> // ��������ջ��ͷ�ļ�

char text_buffer[100];  // ���ڴ洢��ȡ���ַ���

void Read_File(const char* filename) {
    FILE* file = fopen(filename, "r"); // ��ֻ��ģʽ���ļ�
    if (file == NULL) {
        printf("�޷����ļ� %s\n", filename);
        return;
    }

    while (fgets(text_buffer, sizeof(text_buffer), file) != NULL){
        // ɾ�����з�
        if (text_buffer[strlen(text_buffer) - 1] == '\n') {
            text_buffer[strlen(text_buffer) - 1] = '\0';
        }

        // ���ü��㺯���������ַ��ַ���
        double result = computer_LinkList(text_buffer);

        printf("����: %s\n", text_buffer);
        printf("���: %lf\n", result);
    }
    fclose(file); // �ر��ļ�
}

