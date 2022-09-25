#include<stdio.h>
#include<string.h>
#include<time.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

#include"Play.h"
#include"Play_Xxl.h"



void Show(int piece[][N])
{
	for (int i = 0; i < M - 1; i++)
	{
		printf("         ");
		for (int j = 0; j < N; j++)
		{
			if (piece[i][j]){
				printf("■■ ");
			}
			else{
				printf("     ");
			}
		}
		printf("\n");
	}
	for (int i = 0; i <= 5 * N + 4; i += 2)//i+=2是因为横向占用的是两个位置
	{

		gotoxy(i + 6, 0);
		printf("■");
		gotoxy(i + 6, M - 1);
		printf("■");
	}

	for (int i = 1; i <= M - 1; i++)
	{
		gotoxy(6, i);
		printf("■");
		gotoxy(5 * N + 10, i);
		printf("■");
	}
}

void Add(int piece[][N], int *i)
{

	for (int a = *i; a >= 0; a--)
	{
		for (int j = 0; j < N; j++)
		{
			piece[a + 1][j] = piece[a][j];
		}
	}
	for (int j = 0; j < N; j++)
	{
		piece[0][j] = 0;
	}
	int x = rand() % N;
	for (int j = 0; j < N; j++)
	{
		if (j != x){
			piece[0][j] = 1;
		}
	}
	(*i)++;
	system("cls");
	Show(piece);

}

void Shoot(int piece[][N], int *i)
{
	char key;
	int x;
	int sum = 0;
	int a;
	if (_kbhit())//如果用户按下了键盘中的某个键
	{
		//fflush(stdin);//清空缓冲区的字符


		key = _getch();
		switch (key)
		{
		case 'z':
			x = 0; break;
		case 'x':
			x = 1; break;
		case 'c':
			x = 2; break;
		case 'v':
			x = 3; break;
		case 'b':
			x = 4; break;
		case 'n':
			x = 5; break;
		}
		for (a = *i; a >= 0; a--)
		{
			if (piece[a][x] == 1)
			{
				piece[a + 1][x] = 1;
				break;
			}
		}
		if (a == -1)
		{
			piece[0][x] = 1;
		}

		for (int j = 0; j < N; j++)
		{
			sum += piece[a + 1][j];
		}
		if (sum == N){
			printf("          消灭了一行加油加油       \n");
			for (a++; a < *i; a++)
			{
				for (int j = 0; j < N; j++)
				{
					piece[a][j] = piece[a + 1][j];
				}
			}
			for (int j = 0; j < N; j++)
			{
				piece[*i][j] = 0;
			}
			(*i)--;
		}
		else{
			printf("         哦买噶   射 歪 了 \n");
			if (a == *i){

				(*i)++;
			}
		}
		system("cls");
		Show(piece);
	}

}

void Chu(int piece[][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			piece[i][j] = 0;
		}
	}
}
int Play_Xxl()
{
	system("cls");
	srand((unsigned int)time(NULL));
	int piece[M][N];
	int a;
	Chu(piece);
	Show(piece);
	int i = 0;
	int sudu = 0;
	int grade = 0;
	printf("\n \n    游戏规则如下； \n\n");
	printf("  x 代表第一列  y 代表第二列  c代表第三列  v代表第四列 每行铺满则消除该行\n\n           无尽模式！！     \n\n            GOGOGO!!\n\n");
	system("pause");
	while (1)
	{
		Shoot(piece, &i);
		if (i >= M - 1){ break; }
		Shoot(piece, &i);
		if (i >= M - 1){ break; }
		Add(piece, &i);
		if (i >= M - 1){ break; }
		Shoot(piece, &i);
		if (i >= M - 1){ break; }
		Shoot(piece, &i);
		if (i >= M - 1){ break; }
		if (sudu<40)sudu++;
		Sleep(2000 - sudu * 25);
		grade++;
	}
	gotoxy(50, 8);
	printf("   Game Over!!   ");
	gotoxy(50, 9);
	printf("你的成绩是：%d", grade);
	Sleep(3000);
	system("pause");
	return grade;
}



