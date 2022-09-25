#include<stdio.h>

#define Dxc_N 5                                                          //这里修改宽度  高度  难度
#define Dxc_M 7
#define Random 16
#define Dxc_Gongzhu 520
#define Dxc_Wangzi 521


int Play_Dxc();
void Dxc_setmap(int map[][Dxc_N], int i);
void Dxc_getmap(int map[][Dxc_N], int i);
void Dxc_move(int map[][Dxc_N], int *i1, int *j1, int *energy, int i);
void gotoxy(int x, int y);
void Dxc_Beijing();
