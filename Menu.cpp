#include<stdio.h>
#include<stdlib.h>
#include<Menu.h>
#include<string>
#include <SequenceList.h>
#include<LinkList.h>
#include <cmp.h>
#include<file.h>


int Flag=0;
int File_Flag=0;
void Menu() {

    printf("|------------------- ������ ------------------|\n");
    printf("|                                             |\n");
    printf("|---------------- 1����ջʵ�� ----------------|\n");
    printf("|---------------- 2��˳��ʵ�� ----------------|\n");
    printf("|---------------- 3���ļ�����  ---------------|\n");
    printf("|---------------- 4����    �� ----------------|\n");
    printf("|                                             |\n");
    printf("|------------------- ������ ------------------|\n");
    printf("������˵����ܣ�1-4��:");
     scanf("%d", &Flag);
}
int Back_Meun(){
    return Flag = 0;
}
int GetFlag(){
    return Flag;
}
void remind(){
    printf("������ʽ��=��enter��β\n");
}

int Back_FileMeun() {
    return File_Flag = 0;
}

int GetFlag_FileMeun(){
    return File_Flag;
}


void File_Meun() {
    printf("|---------------- 1��Ĭ�ϲ��Լ� ----------------|\n");
    printf("|---------------- 2��������Լ� ----------------|(��ʹ�þ���·����λ��Simple-calculator�µ����·��)\n");
    printf("|---------------- 3����      �� ----------------|\n");
    printf("������˵����ܣ�1-3��:");
    scanf("%d", &File_Flag);
}

char filename[100];

void file_Meun_Init(){
    File_Meun();
    switch (GetFlag_FileMeun()){
    case 0:
        File_Meun();
        break;
    case 1:
        Read_File("F:/Soft_Project/���ݽṹ/����˳�������/test.txt");
        break;
    case 2:
        printf("�������ļ���ַ��");
        scanf("%s", filename);
        // ���ô����ļ��ĺ���
        Read_File(filename);

        break;
    case 3:
        break;
    default:
        printf("�����������������\n");
        Back_FileMeun();
        break;
    }
    getchar();
    getchar();
}




void Meun_init() {
    Menu();
    switch (GetFlag()) {
    case 0:
        Menu();
        break;
    case 1:
        clearInputBuffer();
        Ans_Link_List();
        break;
    case 2:
        clearInputBuffer();
        Ans_SequenceList();
        break;
    case 3:
        file_Meun_Init();
        Back_Meun();
        break;
    case 4:
        exit(EXIT_FAILURE);
        break;
    default:
        printf("�����������������\n");
        Back_Meun();
        break;
    }
    printf("��ENTER������...");
    getchar();
    system("cls");
}