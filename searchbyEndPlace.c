#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*根据客户提出的终点站名输出航线信息*/
#include "searchbyEndPlace.h"
#include "global_list.h"
//#include "air_ticket.h"
void searchbyEndPlace()
{
	char endpoint[MAX_END];
	printf("请输入到达城市：\n");
	scanf("%s",endpoint);
	AIRcraft *p = aircraftListHead;
	while(p)
	{

		if(strcmp(p->endpoint,endpoint) == 0 )
		{
			printf("\n\n-------------- 航班信息 -------------\n\n");
			printf("航班号：%s\n",p->Airnum);
			printf("起飞城市：%s\n",p->start);
			printf("抵达城市：%s\n",p->endpoint);
			printf("出发日期：%s\n",p->dates);
            printf("起飞时间：%s\n",p->gotime);
            printf("到达时间：%s\n",p->gettime);
            printf("机型：%s\n",p->mode);
			printf("航班票价：%f\n",p->price);
			printf("总票量：%d\n",p->max_pass);
			printf("剩余票量：%d\n",p->remainder);
			printf("\n---------------------------------------\n\n");
			break;
		}
		p = p->airnext;
	}
	if(!p){
		printf("抱歉！没有查询对应的航班...\n");

	}
}
