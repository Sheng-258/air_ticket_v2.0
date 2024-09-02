//showMenu1.c
//函数功能：显示主菜单
//函数参数：无
//函数返回值：无
#include <stdio.h>
#include "showMenu1.h"
#include "rootmeau.h"
#include "passengermeau.h"
#include <stdlib.h>
//#include "air_ticket.h"
void showMenu1()
{
    int choice,Count=0;
    while(1)
    {
        printf("\n");
        printf("\t欢迎进入xx航空订票系统\n");
        printf("*****************************\n");
        printf("*       航空订票客运系统    *\n");
        printf("*        1、航空管理员      *\n");
        printf("*        2、乘客            *\n");
        printf("*        3、退出            *\n");
        printf("请 选 择(1-3):\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:{rootmeau(); break;}//管理员
		case 2:{passengermeau(); break;}//乘客
		case 3:{printf("欢迎下次再次使用\n");exit(0);}//退出程序
		default:
		    {  Count++;
		       if(Count<3)
               {
                   printf("输入错误，还有 %d 次机会，请重新输入\n",3-Count);
               }
               else
               {
                   return;
               }
		       break;
            }
		}

    }
}
