#include<stdio.h>
#include<stdlib.h>
#include<Menu.h>
#include<string>
#include <SequenceList.h>
#include<LinkList.h>
#include <cmp.h>
#include<file.h>
int main() {
    Menu();
	while (1)
	{
		if (GetFlag()==0)
		{
			Menu();
		}else if(GetFlag() == 1){
			clearInputBuffer();
			Ans_Link_List();
		}
		if (GetFlag() == 2){
			clearInputBuffer();
			Ans_SequenceList();
		}
		else if (GetFlag() == 3) {
			Read_File("F:/Soft_Project/���ݽṹ/����˳�������/test.txt");
			Back_Meun();
		}
		else if (GetFlag() == 4) {
			break;
		}

		else if (GetFlag()<0|| GetFlag() >4) {
			printf("�����������������\n");
			Back_Meun();
		}
	}

    return 0;
}
