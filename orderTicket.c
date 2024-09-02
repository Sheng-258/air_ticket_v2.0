#include <stdio.h>
#include <string.h>
#include "global_list.h"
#include "globals.h"
#include "orderTicket.h"

/*办理订票业务*/
void orderTicket()
{
	int choose;
	char airnum[MAX_aircraft_num];
	printf("\n *****乘客订票系统*******\n");
	printf("\t\t 1、选择航班订票\n");
	printf("\t\t 2、返回上一级\n");
	printf("\n*************************\n");
	printf("请选择：");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			   if(acount==0)
               {
                   printf("对不起，因天气原因，所有航班停飞\n");
                   break;
               }
			   AIRcraft *p =aircraftListHead;
			   printf("\n ********全部的航班信息*******\n");
			   printf("航班号     出发地     目的地    起飞日期    出发时间   到达时间     机型     乘客定额    余票    票价\n");
			   while(p)
               {
                printf("%s        %s          %s       %s          %s         %s           %s       %d          %d       %f\n",p->Airnum,p->start,p->endpoint,p->dates,p->gotime,p->gettime,p->mode,p->max_pass,p->remainder,p->price);
                p=p->airnext;

               }
               printf("请输入你要预定的航班号：");
               scanf("%s",airnum);
               AIRcraft *pr =aircraftListHead;
               while(pr)
               {
                   if(strcmp(pr->Airnum,airnum)==0)
                   {
                       printf("航班号     出发地     目的地    起飞日期    出发时间   到达时间     机型    票价\n");
                       printf("%s         %s         %s        %s          %s         %s           %s      %d",pr->Airnum,pr->start,pr->endpoint,pr->dates,pr->gotime,pr->gettime,pr->mode,pr->price);
                       printf("确认购票吗？(y/n) :");
                       char sel;
                       scanf("%c",&sel);
                       if(sel=='y'|| sel=='Y')
                       {
                           if(pr->remainder==0)
                           {
                               printf("抱歉，此航班机票已售罄\n");

                           }
                           else
                           {   if(pr->max_pass - pr->remainder != MAXBOOK)
                               {
                                 printf("请输入您的信息：\n");
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].Airnum,airnum);
                                 printf("姓名：\n");
                                 scanf("%s",pr->passenger[pr->max_pass - pr->remainder].name);
                                 printf("身份证号：\n");
                                 scanf("%s",pr->passenger[pr->max_pass - pr->remainder].didentify);
                                 printf("座位等级：\n");
                                 scanf("%d",&pr->passenger[pr->max_pass - pr->remainder].grade);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].start,pr->start);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].endpoint,pr->endpoint);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].dates,pr->dates);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].gotime,pr->gotime);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].gettime,pr->gettime);
                               }
                               pr->remainder--;
                               printf("恭喜订票成功！\n");
                           }
                       }
                       else
                       {
                           printf("即将退出。\n");
                       }
                       break;

                   }
                   else
                   {
                       pr=pr->airnext;
                   }

               }
               if(pr == NULL)
                {
		         printf("抱歉！没有查询对应的航班...\n");
	            }
			break;
		case 2:
			return;
	}

}
