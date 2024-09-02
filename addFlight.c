//函数功能：添加航班,后续再加判断航班信息是否重复加入
#include <stdio.h>
#include <stdlib.h>
#include "addFlight.h"
#include "globals.h"
#include "global_list.h"
//#include "air_ticket.h"
void addFlight()
{
    char c;
    int i=0;

    if (acount >= MAXAIR)
    {
        printf("不能添加航班信息，已达到最大航班数量\n");
        return;
    }
    else
    {
        printf("是否要添加航班信息(Y/N)?");
        scanf(" %c",&c);
        while(c=='Y' || c== 'y')
        {
            AIRcraft *p = NULL;

            p = (AIRcraft *)malloc(sizeof(AIRcraft));
            if (p==NULL)
            {
            printf("内存分配失败，请联系系统管理员! \n");
            exit(0);
            }
            printf("请输入航班信息：\n");
            printf("航班号：");
            scanf("%s",p->Airnum);//如果此方法不对，就用strcpy
            printf("出发地：");
            scanf("%s",p->start);
            printf("目的地：");
            scanf("%s",p->endpoint);
            printf("飞行日期：");
            scanf("%s",p->dates);
            printf("出发时间：");
            scanf("%s",p->gotime);
            printf("到达时间：");
            scanf("%s",p->gettime);
            printf("机型：");
            scanf("%s",p->mode);
            printf("乘客定额：");
            scanf("%d",&p->max_pass);
            printf("余票：");
            scanf("%d",&p->remainder);
            printf("价格：");
            scanf("%f",&p->price);
            p->airnext = NULL;


            if(aircraftListHead==NULL)
            {
                aircraftListHead=p;//新建的节点(航班信息链表节点)为头节点
            }
            else
            {   AIRcraft *pr = aircraftListHead;
                while(pr->airnext != NULL)//若为移动到表尾，则继续移动
                {
                    pr=pr->airnext;
                }
                pr->airnext = p;
            }

            i++;
            acount++;
            if (acount >= MAXAIR)
            {
              printf("不能再添加航班信息，已达到最大航班数量\n");
              return;
            }
            else
            {
               printf("是否要继续添加航班信息(Y/N)?");
               scanf(" %c",&c);
            }


        }

       printf("您添加了 %d 个航班信息！\n",i);

    }

}
