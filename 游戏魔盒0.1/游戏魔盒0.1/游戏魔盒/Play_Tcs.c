#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>


#include"Play_Tcs.h"
#include"Play.h"
#ifndef __cplusplus

#endif





int key = 72;

int changeFlag = 0;

int sorce = 0;

int i;
void Tcs_guize()
{
	system("cls");
	gotoxy(10, 20);
	printf("\n\n���������С��\n\n");
	system("pause");
}

int Play_Tcs()
{
	system("cls");
	gotoxy(20, 10);
	printf("���������С��\n\n\n\n");
	system("pause");
	system("cls");
	drawMap();
	while (1)
	{
		keyDown();
		if (!snakeStatus())
			break;
		createFood();
		Sleep(snake.speed);
	}

	gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2);
	printf("Game Over!\n");
	gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2 + 1);
	printf("������Ϸ�÷�Ϊ��%d\n", sorce);
	system("pause");
	return sorce;
}
void drawMap()
{

	for (i = 0; i <= MAPWIDTH; i += 2)//i+=2����Ϊ����ռ�õ�������λ��
	{

		gotoxy(i, 0);
		printf("��");
		gotoxy(i, MAPHEIGHT);
		printf("��");
	}

	for (i = 1; i < MAPHEIGHT; i++)
	{
		gotoxy(0, i);
		printf("��");
		gotoxy(MAPWIDTH, i);
		printf("��");
	}


	while (1)
	{
		srand((unsigned int)time(NULL));
		food.x = rand() % (MAPWIDTH - 4) + 2;
		food.y = rand() % (MAPHEIGHT - 2) + 1;

		if (food.x % 2 == 0)
			break;
	}
	gotoxy(food.x, food.y);
	printf("*");

	snake.len = 3;
	snake.speed = 200;
	snake.x[0] = MAPWIDTH / 2 + 1;
	snake.y[0] = MAPHEIGHT / 2;
	gotoxy(snake.x[0], snake.y[0]);
	printf("��");


	for (i = 1; i < snake.len; i++)
	{
		snake.x[i] = snake.x[i - 1] + 2;
		snake.y[i] = snake.y[i - 1];
		gotoxy(snake.x[i], snake.y[i]);
		printf("��");
	}
	gotoxy(MAPWIDTH - 2, 0);
	return;
}

void keyDown()
{
	int pre_key = key;
	if (_kbhit())//����û������˼����е�ĳ����
	{
		fflush(stdin);//��ջ��������ַ�


		key = _getch();//��һ�ε��÷��صĲ���ʵ��ֵ
		key = _getch();//�ڶ��ε��÷���ʵ��ֵ
	}


	if (changeFlag == 0)
	{
		gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
		printf("  ");
	}

	//���ߵ�ÿһ��������ǰ�ƶ�һ��
	for (i = snake.len - 1; i > 0; i--)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}
	if (pre_key == 72 && key == 80)
		key = 72;
	if (pre_key == 80 && key == 72)
		key = 80;
	if (pre_key == 75 && key == 77)
		key = 75;
	if (pre_key == 77 && key == 75)
		key = 77;


	switch (key)
	{
	case 75:
		snake.x[0] -= 2;//����
		break;
	case 77:
		snake.x[0] += 2;//����
		break;
	case 72:
		snake.y[0]--;//����
		break;
	case 80:
		snake.y[0]++;//����
		break;
	}
	gotoxy(snake.x[0], snake.y[0]);
	printf("��");
	gotoxy(MAPWIDTH - 2, 0);
	changeFlag = 0;
	return;
}

void createFood()
{
	if (snake.x[0] == food.x && snake.y[0] == food.y)
	{
		while (1)
		{
			int flag = 1;
			srand((unsigned int)time(NULL));
			food.x = rand() % (MAPWIDTH - 4) + 2;
			food.y = rand() % (MAPHEIGHT - 2) + 1;

			for (i = 0; i < snake.len; i++)
			{
				if (snake.x[i] == food.x && snake.y[i] == food.y)
				{
					flag = 0;
					break;
				}
			}
			//������ɵ�ʳ�ﲻ�ܺ�����Ϊ������Ҳ����������������������
			if (flag && food.x % 2 == 0)
				break;
		}

		//����ʳ��
		gotoxy(food.x, food.y);
		printf("*");

		snake.len++;
		sorce += 10;//ÿ��ʳ���10��
		snake.speed -= 5;//�ٶȻ�Խ��Խ��
		changeFlag = 1;
	}
	return;
}

int snakeStatus()
{
	if (snake.y[0] == 0 || snake.y[0] == MAPHEIGHT)
		return 0;
	if (snake.x[0] == 0 || snake.x[0] == MAPWIDTH)
		return 0;
	for (i = 1; i < snake.len; i++)
	{
		if (snake.x[i] == snake.x[0] && snake.y[i] == snake.y[0])
			return 0;
	}
	return 1;
}

