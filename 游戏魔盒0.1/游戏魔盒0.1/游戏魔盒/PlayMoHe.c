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
	printf("                *     1��������Ϸ     * \n");
	printf("                *                     * \n");
	printf("                *     2����������     * \n");
	printf("                *                     * \n");
	printf("                *     3����ĳɼ�     * \n");
	printf("                *                     * \n");
	printf("                *     4���˳�         * \n");
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
	printf("                *     1��̰����       * \n");
	printf("                *                     * \n");
	printf("                *     2�����³�       * \n");
	printf("                *                     * \n");
	printf("                *     3��������       * \n");
	printf("                *                     * \n");
	printf("                *     4��������Ϸ     * \n");
	printf("                *                     * \n");
	printf("                * * * * * * * * * * * * \n");
	printf("\n\n\n\n");
}
void Play_Gengduo(){
	system("cls");
	printf("\n\n\n\n\n\n   ----------------------�����ڴ�-----------------------\n\n\n\n\n\n");
	system("pause");
}

void Show_guanyuwomen()
{
	system("cls");
	printf("\n    ����:��ʱ���ı��ƴ��ѧ������˼�룬���ڷܶ������ڴ��¡�ѧ��c���ԣ�����Java��Ŀǰ����ѧϰ�߼�Java����������е����ǵ���Ʒ����Ϸħ�С���������Щ֪ʶ�����ϵ��������ġ�\n\n");
	printf("    ��Ϸ�滮:�ټ򵥵���ƶ���Ҫ�����߻��ѵ�һ����Ѫ�������ƷҲ�����⡣Ŀǰ������һ���ռ�������˼���С��Ϸ����Ϊװ����Щ��Ϸ����������֮�����Ƿ������Ϸ����࣬�����Ը���ѡ���Ը��࣬�����������ռ䣬����Щ��Ϸ������ã������û����Ը���ĸ����Լ��������ҵ��Լ���Ҫ���ǿ��һ�޶�����Ϸ��");
	printf("�������֣����������ݣ���Ӧ�ٶȸ�������������Ϣ����׼ȷ���廯����Щ�����������ǵ���Ŀ����ӵ�е����ʡ������������û����飬��������û�����Ⱥ����ʶȡ�\n\n\n\n\n");
	system("pause");
}

void Show_gengduo()
{
	system("cls");
	printf("\n\n\n\n\n\n\n       ף��������죬��ӭ�´�����\n\n\n\n");
	system("pause");
}

void Show_chengji(struct Palyer player)
{
	system("cls");
	gotoxy(20, 10);
	printf("̰������߳ɼ�:%d", player.Tcs);
	gotoxy(20, 11);
	printf("���³���߳ɼ�:%d", player.Dxc);
	gotoxy(20, 12);
	printf("��������߳ɼ�:%d", player.Xxl);
	gotoxy(20, 13);
	printf("��Ϸ����:%d\n\n\n", player.x);
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
		printf("����������Ҫ�����:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Show_Play();
			printf("��������Ҫ����Ϸ�����:");
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
