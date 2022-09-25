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
	printf("\n\n方向键控制小蛇\n\n");
	system("pause");
}

int Play_Tcs()
{
	system("cls");
	gotoxy(20, 10);
	printf("方向键控制小蛇\n\n\n\n");
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
	printf("本次游戏得分为：%d\n", sorce);
	system("pause");
	return sorce;
}
void drawMap()
{

	for (i = 0; i <= MAPWIDTH; i += 2)//i+=2是因为横向占用的是两个位置
	{

		gotoxy(i, 0);
		printf("■");
		gotoxy(i, MAPHEIGHT);
		printf("■");
	}

	for (i = 1; i < MAPHEIGHT; i++)
	{
		gotoxy(0, i);
		printf("■");
		gotoxy(MAPWIDTH, i);
		printf("■");
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
	printf("■");


	for (i = 1; i < snake.len; i++)
	{
		snake.x[i] = snake.x[i - 1] + 2;
		snake.y[i] = snake.y[i - 1];
		gotoxy(snake.x[i], snake.y[i]);
		printf("■");
	}
	gotoxy(MAPWIDTH - 2, 0);
	return;
}

void keyDown()
{
	int pre_key = key;
	if (_kbhit())//如果用户按下了键盘中的某个键
	{
		fflush(stdin);//清空缓冲区的字符


		key = _getch();//第一次调用返回的不是实际值
		key = _getch();//第二次调用返回实际值
	}


	if (changeFlag == 0)
	{
		gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
		printf("  ");
	}

	//将蛇的每一节依次向前移动一节
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
		snake.x[0] -= 2;//往左
		break;
	case 77:
		snake.x[0] += 2;//往右
		break;
	case 72:
		snake.y[0]--;//往上
		break;
	case 80:
		snake.y[0]++;//往下
		break;
	}
	gotoxy(snake.x[0], snake.y[0]);
	printf("■");
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
			//随机生成的食物不能横坐标为奇数，也不能在蛇身，否则重新生成
			if (flag && food.x % 2 == 0)
				break;
		}

		//绘制食物
		gotoxy(food.x, food.y);
		printf("*");

		snake.len++;
		sorce += 10;//每个食物得10分
		snake.speed -= 5;//速度会越来越快
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

