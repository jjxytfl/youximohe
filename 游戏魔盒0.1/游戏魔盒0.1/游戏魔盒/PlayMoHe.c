#include<stdio.h>

#include"Play.h"
#include"Play_Dxc.h"
#include"Play_Xxl.h"
#include"Play_Tcs.h"

struct Palyer{
	int Tcs;
	int Dxc;
	int Xxl;
	int x;
};

void Show_main()
{
	system("cls");
	printf("\n\n\n\n");
	printf("                * * * * * * * * * * * * \n");
	printf("                *                     * \n");
	printf("                *     1、所有游戏     * \n");
	printf("                *                     * \n");
	printf("                *     2、关于我们     * \n");
	printf("                *                     * \n");
	printf("                *     3、你的成绩     * \n");
	printf("                *                     * \n");
	printf("                *     4、退出         * \n");
	printf("                *                     * \n");
	printf("                * * * * * * * * * * * * \n");
	printf("\n\n\n\n");
}

void Show_Play()
{
	system("cls");
	printf("\n\n\n\n");
	printf("                * * * * * * * * * * * * \n");
	printf("                *                     * \n");
	printf("                *     1、贪吃蛇       * \n");
	printf("                *                     * \n");
	printf("                *     2、地下城       * \n");
	printf("                *                     * \n");
	printf("                *     3、消消乐       * \n");
	printf("                *                     * \n");
	printf("                *     4、更多游戏     * \n");
	printf("                *                     * \n");
	printf("                * * * * * * * * * * * * \n");
	printf("\n\n\n\n");
}
void Play_Gengduo(){
	system("cls");
	printf("\n\n\n\n\n\n   ----------------------尽情期待-----------------------\n\n\n\n\n\n");
	system("pause");
}

void Show_guanyuwomen()
{
	system("cls");
	printf("\n    背景:新时代的本科大二学生，有思想，敢于奋斗，勇于创新。学了c语言，初级Java，目前正在学习高级Java。这个比赛中的我们的作品“游戏魔盒”便是在这些知识基础上诞生出来的。\n\n");
	printf("    游戏规划:再简单的设计都需要创作者花费的一番心血，这个作品也不例外。目前它是在一个空间里放入了几个小游戏，成为装下这些游戏的容器。在之后，我们放入的游戏会更多，可能性更大，选择性更多，甚至创造多个空间，把这些游戏归类放置，便于用户可以更快的根据自己的需求找到自己想要的那款独一无二的游戏。");
	printf("容易上手，操作会更便捷，反应速度更灵敏，数据信息更加准确具体化，这些都将会是我们的项目中所拥有的性质。不仅会提升用户体验，还能提高用户满意度和舒适度。\n\n\n\n\n");
	system("pause");
}

void Show_gengduo()
{
	system("cls");
	printf("\n\n\n\n\n\n\n       祝您生活愉快，欢迎下次再来\n\n\n\n");
	system("pause");
}

void Show_chengji(struct Palyer player)
{
	system("cls");
	gotoxy(20, 10);
	printf("贪吃蛇最高成绩:%d", player.Tcs);
	gotoxy(20, 11);
	printf("地下城最高成绩:%d", player.Dxc);
	gotoxy(20, 12);
	printf("消消乐最高成绩:%d", player.Xxl);
	gotoxy(20, 13);
	printf("游戏次数:%d\n\n\n", player.x);
	system("pause");
}

int main()
{
	struct Palyer player_m = { 0, 0, 0, 0 };
	struct Palyer player = {0,0,0,0};
	int choice=0;
	int choice_play=0;
	while (1){
		Show_main();
		printf("请输入您需要的序号:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Show_Play();
			printf("请输入您要玩游戏的序号:");
			scanf("%d", &choice_play);
			switch (choice_play){
			case 1:
				player_m.Tcs=Play_Tcs();
				if (player_m.Tcs > player.Tcs)player.Tcs = player_m.Tcs;
				player.x++; break;
			case 2:
				player_m.Dxc=Play_Dxc();
				if (player_m.Dxc > player.Dxc)player.Dxc = player_m.Dxc;
				player.x++;  break;
			case 3:
				player_m.Xxl=Play_Xxl(); 
				if (player_m.Xxl > player.Xxl)player.Xxl = player_m.Xxl;
				player.x++;  break;
			case 4:
				Play_Gengduo(); break;
			}

			break;
		case 2:
			Show_guanyuwomen();
			break;
		case 3:
			Show_chengji(player);
			break;
		case 4:
			Show_gengduo();
			break;
		}
		if (choice == 4)break;
	}

	//Play_Xxl();
	//Play_Tcs();
	//Play_Dxc();

	return 0;
}
