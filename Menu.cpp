#include<stdio.h>
#include<stdlib.h>
#include<Menu.h>
#include<string>


int Flag=0;

void Menu() {

    printf("|--------------------- ������ -----------------------|\n");
    printf("|                                                    |\n");
    printf("|------------------ 1����ջʵ�� ---------------------|\n");
    printf("|------------------ 2��˳��ʵ�� ---------------------|\n");
    printf("|------------------ 3����    �� ---------------------|\n");
    printf("|                                                    |\n");
    printf("|--------------------- ������ -----------------------|\n");
    printf("������˵����ܣ�1-3��:");
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
