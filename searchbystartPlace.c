#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*���ݿͻ���������վ�����������Ϣ*/
#include "searchbystartPlace.h"
#include "global_list.h"
//#include "air_ticket.h"
void searchbystartPlace()
{
	char start[MAX_start];
	printf("���������վ��\n");
	scanf("%s",start);
	AIRcraft *p = aircraftListHead;
	while(p)
	{

		if(strcmp(p->start,start) == 0 )
		{
			printf("\n\n-------------- ������Ϣ -------------\n\n");
			printf("����ţ�%s\n",p->Airnum);
			printf("��ɳ��У�%s\n",p->start);
			printf("�ִ���У�%s\n",p->endpoint);
			printf("�������ڣ�%s\n",p->dates);
            printf("���ʱ�䣺%s\n",p->gotime);
            printf("����ʱ�䣺%s\n",p->gettime);
            printf("���ͣ�%s\n",p->mode);
			printf("����Ʊ�ۣ�%f\n",p->price);
			printf("��Ʊ����%d\n",p->max_pass);
			printf("ʣ��Ʊ����%d\n",p->remainder);
			printf("\n---------------------------------------\n\n");
			break;
		}
		p = p->airnext;
	}
	if(!p){
		printf("��Ǹ��û�в�ѯ��Ӧ�ĺ���...\n");

	}
}
