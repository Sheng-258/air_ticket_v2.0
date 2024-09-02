#include <stdio.h>
/*办理退票业务*/
#include "refund_ticket.h"
#include "global_list.h"
#include <string.h>
void refund_ticket()
{
	char airnum[MAX_aircraft_num];
	char Name[NAME];
	char Didentify[DID];
	int ticket;
	char choose;
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
                    printf("请再次确实是否要进行退票(y/n)?\n");
                    scanf("%c",&choose);
                    if(choose=='Y'|| choose=='y')
                    {
                        if(i== ticket-1)//判断是否为最后一个
                        {
                            memset(&p->passenger[i], 0, sizeof(p->passenger));
                        }
                        else
                        {
                            for(int j=i;j<ticket-1;j++)
                            {
                                p->passenger[j]=p->passenger[j+1];//检查一下这种是按地址值的操作，操作结构体数组，数组的名字代表数组的首地址
                            }
                            p->remainder++;
                            printf("退票成功！\n");
                        }

                    }
                    else
                    {
                        printf("即将返回上一级！\n");
                    }
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
