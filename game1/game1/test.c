#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void memu()
{
	printf("********************\n");
	printf("*******1.play*******\n");
	printf("*******0.exit*******\n");
	printf("********************\n");
}

void game()
{
	char ret=0;
	char board[ROW][COL]={0};//存放棋子信息
	InitBoard(board, ROW, COL);//初始化棋子
	DisplayBoard(board,ROW,COL);//打印棋盘
	//下棋
	while(1)
	{
		PlayerMove(board,ROW,COL);//玩家下棋
		DisplayBoard(board,ROW,COL);
		ret=IsWen(board,ROW,COL);
		if(ret!='C')
		{
			break;
		}
		ComputerMove(board,ROW,COL);//电脑下棋
		DisplayBoard(board,ROW,COL);
		ret=IsWen(board,ROW,COL);
		if(ret!='C')
		{
			break;
		}
	}
	if(ret=='*')
		printf("玩家赢\n");
	else if(ret=='#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}


void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
//  随机数   返回类型   函数  指针
	do
	{
		memu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			printf("三子棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	}while(input);
}


int main()
{
	test();
	return 0;
}

