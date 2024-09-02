//查询订票信息
#include <stdio.h>
#include "refund_ticket.h"
#include "global_list.h"
#include <string.h>
#include "CheckBookingInformation.h"
void CheckBookingInformation()
{
    char airnum[MAX_aircraft_num];
	char Name[NAME];
	char Didentify[DID];
	int ticket;

    printf("请输入您预定的航班号：\n");
    scanf("%s",airnum);
    AIRcraft *p =aircraftListHead;
    while(p)
    {
        if(strcmp(p->Airnum,airnum)==0)
        {
            printf("请输入您的名字：\n");
            scanf("%s",Name);
            printf("请输入您的身份证号：\n");
            scanf("%s",Didentify);
            ticket=p->max_pass - p->remainder;
            for(int i=0;i<ticket;i++)
            {
                if(strcmp(p->passenger[i].name,Name)==0 && strcmp(p->passenger[i].didentify,Didentify)==0)
                {
                      printf("您的订票信息：\n");
                      printf("航班号：%s\n",p->Airnum);
                      printf("姓名：%s\n",p->passenger[i].name);
                      printf("身份证号：%s\n",p->passenger[i].didentify);
                      printf("座位等级：%d\n",p->passenger[i].grade);
                      printf("出发地：%s\n",p->start);
                      printf("目的地：%s\n",p->endpoint);
                      printf("出发日期：%s\n",p->dates);
                      printf("出发时间：%s\n",p->gotime);
                      printf("到达时间：%s\n",p->gettime);
                      printf("机型：%s\n",p->mode);
                      printf("票价：%f\n",p->price);
                      printf("即将返回上一级(y/n)！\n");
                      return;
                }

            }
            printf("抱歉，您输入信息有误，未找到对应乘客信息,即将返回上一级\n");
            return;

        }
        p=p->airnext;
    }
    printf("抱歉，您输入航班号有误，或者没有此航班信息\n");
}
