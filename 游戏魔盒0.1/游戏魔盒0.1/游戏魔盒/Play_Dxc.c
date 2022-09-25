#include<stdio.h>
#include<string.h>
#include<time.h>
#include <Windows.h>//
#include <conio.h>//
#include<conio.h>

#include"Play_Dxc.h"






void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int map[Dxc_M + 1][Dxc_N];    //�����д���ŵ������б�����ʾ��ջ���ƻ���������û��Խ�����    δ���������
int Play_Dxc()
{
	system("cls");
	srand((unsigned int)time(NULL));
	Dxc_Beijing();        //////
	int energy = 10;//����
	int i = 1;
	int i1;
	int j1;
	int sign;
	while (1)
	{
		Dxc_setmap(map[Dxc_N], i);
		i1 = 0; j1 = 0;
		while (1)
		{
			system("cls");
			printf("       ���ӵ�ǰ����:  %d \n\n\n\n", energy);
			Dxc_getmap(map[Dxc_N], i);
			Dxc_move(map[Dxc_N], &i1, &j1, &energy, i);
			if (energy < 0 || (i1 == i&&j1 == Dxc_N - 1))break;
		}



		if (energy < 0){
			printf("           Game Over!   ���յ÷�:  %d \n", i * 10 + energy); Sleep(3000); system("pause"); return (i * 10 + energy);
		}
		if (i1 == i&&j1 == Dxc_N - 1){

			if (i1 == Dxc_M - 1 && j1 == Dxc_N - 1){
				printf("               * * * * * * * * * * * * * * * *   \n  ");
				printf("               Victory!   ���յ÷�:  %d \n", i * 10 + energy);
				printf("               * * * * * * * * * * * * * * * *   \n  "); Sleep(3000); system("pause");return (i * 10 + energy);
			}
			printf("            ����");
			for (int a = 0; a < i; a++)
			{
				printf(" ��");
			}
			printf("��ץ���� !!   ��1��������  ��2~����)\n");

			while (1)
			{
				scanf_s("%d", &sign);
				while (getchar() != '\n');
				if (sign == 1 || sign == 2)
				{
					break;
				}
				printf("û������ѡ����Ŷ!\n");
			}
			if (sign == 2){
				printf("        ������δ�ȳ�   �����յ÷�:  %d \n", i * 10 + energy); Sleep(3000); system("pause"); return (i * 10 + energy); break;
			}
			i++;
		}
	}
	Sleep(3000);
	system("pause");
	return (i * 10 + energy);
}

void Dxc_move(int map[][Dxc_N], int *i1, int *j1, int *energy, int i)
{
	char course;//����
	while (1)
	{
		scanf("%c", &course);
		while (getchar() != '\n');
		if (course == 's' || course == 'd'){
			if (*i1 == i&&course == 's'){
				printf("ײǽ��\n");
				continue;
			}
			if (*j1 == Dxc_N - 1 && course == 'd'){
				printf("ײǽ��\n");
				continue;
			}
			break;
		}
		else if (course == 'w' || course == 'a'){
			printf("��������ʿ����������\n");
		}
		else{
			printf("����s/d  �����ƶ�\n");
		}
	}
	if (course == 's'){
		(*i1)++;
	}
	if (course == 'd'){
		(*j1)++;
	}
	if (map[*i1][*j1] == 15){//*2
		*energy *= 2;
		map[*i1][*j1] = 100; return;
	}
	if (map[*i1][*j1] == 0){//0
		*energy = 0;
		map[*i1][*j1] = 100; return;
	}
	if (map[*i1][*j1] == Dxc_Gongzhu){
		*energy += 5; return;////huodenengliang
	}
	*energy += map[*i1][*j1];
	map[*i1][*j1] = 100; return;

}

void Dxc_setmap(int map[][Dxc_N], int i)
{
	for (int i1 = 0; i1 <= i; i1++)
	{
		for (int j1 = 0; j1 < Dxc_N; j1++)
		{
			map[i1][j1] = rand() % Random - 2 * i;
		}
	}
	map[0][0] = Dxc_Wangzi;
	map[i][Dxc_N - 1] = Dxc_Gongzhu;

}

void Dxc_getmap(int map[][Dxc_N], int i)
{
	for (int i1 = 0; i1 <= i; i1++)
	{
		for (int j1 = 0; j1 < Dxc_N; j1++)
		{
			if (map[i1][j1] == 0){
				printf("      ը��"); continue;
			}
			if (map[i1][j1] == 15){
				printf("      ��Ϣ"); continue;
			}
			if (map[i1][j1] == 100){//lvjing
				printf("      ����"); continue;
			}
			if (map[i1][j1] == Dxc_Gongzhu){
				printf("      ����"); continue;
			}
			if (map[i1][j1] == Dxc_Wangzi){
				printf("      �Ǳ�"); continue;
			}
			printf("%10d", map[i1][j1]);
		}
		printf("\n\n");
	}
	i++;
	for (int j = 1; j <= 2 * i; j++)
	{
		gotoxy(4, j + 3);
		printf("��");
		gotoxy(4 + 10 * Dxc_N, j + 3);
		printf("��");
	}
	for (int j = 0; j <= 10 * Dxc_N; j += 2)//j+=2����Ϊ����ռ�õ�������λ��
	{
		gotoxy(j + 4, 3);
		printf("��");
		gotoxy(j + 4, 3 + 2 * i);
		printf("��");
	}
	printf("\n\n");
	printf("������ʾ��  s����  d����\n");

}

void Dxc_Beijing()
{
	printf("\n    һЩ��ħץס�˹��������������˵��³ǵ����½ǡ����³�����M*N��������ɵĶ�ά��������Ӣ�µ���ʿ��������������ϽǵĳǱ�������봩�����³ǲ�ͨ���Կ���ħ�����ȹ�����\n");
	printf("\n    ��ʿ�ĳ�ʼ����Ϊ��10 ��������Ľ���������ĳһʱ��С��0����������������\n");
	printf("\n��Щ�����ɶ�ħ�����������ʿ�ڽ�����Щ����ʱ��ʧȥ��������(���������ֵΪ�����������ʾ�������е����������ֵ���ʾ��ʿ����ʧ��������) ; �еķ������������ʿ����������ħ����(���������ֵΪ�����������ʾ��ʿ�����ӽ����㣩���еķ�����Խ�����Ϣ���ڴ˷�����ʿ���Խ��������з��������еķ������е��ף�����˷�����ʿ�Ľ���ֵ���Ϊ0��������һ����\n");
	printf("\nΪ�˾��쵽�﹫������ʿ����ÿ��ֻ���һ������ƶ�һ����\n\n\n");
	printf("��һ����������ȥ����Ҫ������\n\n\n");
	system("pause");
}

