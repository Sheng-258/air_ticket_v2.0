//函数功能：显示航班的订票信息
//首先选择显示哪一个航班订票信息
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printOrderCustomByAirNum1.h"
#include "global_list.h"
//#include "air_ticket.h"
void printOrderCustomByAirNum1()
{
    int i;
    int passnum;
    char Airnum[MAX_aircraft_num];
    printf("请输入查询航班号：");
    scanf("%s",Airnum);

    AIRcraft *p = aircraftListHead;

    while(p)
    {
		if(strcmp(p->Airnum,Airnum) == 0 )
		{
			if(p->remainder == p->max_pass)
			{
				printf("该航班没有旅客预定.......\n");
			}
            else
            {   passnum = p->max_pass - p->remainder;
				printf("该航班一共有%d 个旅客，信息如下: \n",passnum);
                printf("航班号     姓名         身份证        座位等级      出发地     目的地      出发日期   出发时间     到达时间\n");

				for(i = 0; i < passnum; i++)
                    {
					 printf("%s\t %s\t \t %s\t \t %d \t %s \t %s \t %s \t %s \t %s\n", p->Airnum, p->passenger[i].name, p->passenger[i].didentify,p->passenger[i].grade,\
                     p->passenger[i].start,p->passenger[i].endpoint,p->passenger[i].dates,p->passenger[i].gotime,p->passenger[i].gettime);
				    }
			}
			break;
		}
		p = p->airnext;
	}
	if(!p)
	{
		printf("航班号有误！请检查.........\n\n");
	}


}
