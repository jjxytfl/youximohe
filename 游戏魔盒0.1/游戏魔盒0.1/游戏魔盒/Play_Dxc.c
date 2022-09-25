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

int map[Dxc_M + 1][Dxc_N];    //将此行代码放到函数中报错，显示堆栈被破坏，可是又没有越界操作    未解决！！！
int Play_Dxc()
{
	system("cls");
	srand((unsigned int)time(NULL));
	Dxc_Beijing();        //////
	int energy = 10;//能量
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
			printf("       王子当前能量:  %d \n\n\n\n", energy);
			Dxc_getmap(map[Dxc_N], i);
			Dxc_move(map[Dxc_N], &i1, &j1, &energy, i);
			if (energy < 0 || (i1 == i&&j1 == Dxc_N - 1))break;
		}



		if (energy < 0){
			printf("           Game Over!   最终得分:  %d \n", i * 10 + energy); Sleep(3000); system("pause"); return (i * 10 + energy);
		}
		if (i1 == i&&j1 == Dxc_N - 1){

			if (i1 == Dxc_M - 1 && j1 == Dxc_N - 1){
				printf("               * * * * * * * * * * * * * * * *   \n  ");
				printf("               Victory!   最终得分:  %d \n", i * 10 + energy);
				printf("               * * * * * * * * * * * * * * * *   \n  "); Sleep(3000); system("pause");return (i * 10 + energy);
			}
			printf("            公主");
			for (int a = 0; a < i; a++)
			{
				printf(" 又");
			}
			printf("被抓走了 !!   按1继续救她  ；2~不救)\n");

			while (1)
			{
				scanf_s("%d", &sign);
				while (getchar() != '\n');
				if (sign == 1 || sign == 2)
				{
					break;
				}
				printf("没有其他选项了哦!\n");
			}
			if (sign == 2){
				printf("        公主尚未救出   ，最终得分:  %d \n", i * 10 + energy); Sleep(3000); system("pause"); return (i * 10 + energy); break;
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
	char course;//方向
	while (1)
	{
		scanf("%c", &course);
		while (getchar() != '\n');
		if (course == 's' || course == 'd'){
			if (*i1 == i&&course == 's'){
				printf("撞墙了\n");
				continue;
			}
			if (*j1 == Dxc_N - 1 && course == 'd'){
				printf("撞墙了\n");
				continue;
			}
			break;
		}
		else if (course == 'w' || course == 'a'){
			printf("真正的勇士不会退缩！\n");
		}
		else{
			printf("输入s/d  进行移动\n");
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
				printf("      炸弹"); continue;
			}
			if (map[i1][j1] == 15){
				printf("      休息"); continue;
			}
			if (map[i1][j1] == 100){//lvjing
				printf("      经过"); continue;
			}
			if (map[i1][j1] == Dxc_Gongzhu){
				printf("      公主"); continue;
			}
			if (map[i1][j1] == Dxc_Wangzi){
				printf("      城堡"); continue;
			}
			printf("%10d", map[i1][j1]);
		}
		printf("\n\n");
	}
	i++;
	for (int j = 1; j <= 2 * i; j++)
	{
		gotoxy(4, j + 3);
		printf("■");
		gotoxy(4 + 10 * Dxc_N, j + 3);
		printf("■");
	}
	for (int j = 0; j <= 10 * Dxc_N; j += 2)//j+=2是因为横向占用的是两个位置
	{
		gotoxy(j + 4, 3);
		printf("■");
		gotoxy(j + 4, 3 + 2 * i);
		printf("■");
	}
	printf("\n\n");
	printf("操作提示：  s向下  d向右\n");

}

void Dxc_Beijing()
{
	printf("\n    一些恶魔抓住了公主并将她关在了地下城的右下角。地下城是由M*N个房间组成的二维网格。我们英勇的骑士最初被安置在左上角的城堡里，他必须穿过地下城并通过对抗恶魔来拯救公主。\n");
	printf("\n    骑士的初始能量为：10 ，如果他的健康点数在某一时刻小于0，他会立即死亡。\n");
	printf("\n有些房间由恶魔守卫，因此骑士在进入这些房间时会失去能量点数(若房间里的值为负整数，则表示房间内有敌人埋伏，数值则表示骑士将损失能量点数) ; 有的房间包含增加骑士能量点数的魔法球(若房间里的值为正整数，则表示骑士将增加健康点）；有的房间可以进行休息（在此房间骑士可以将能量进行翻倍）；有的房间埋有地雷（进入此房间骑士的健康值会变为0，还能走一步）\n");
	printf("\n为了尽快到达公主，骑士决定每次只向右或向下移动一步。\n\n\n");
	printf("第一步最难迈出去，需要按两次\n\n\n");
	system("pause");
}

