#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*���ݿͻ�������յ�վ�����������Ϣ*/
#include "searchbyEndPlace.h"
#include "global_list.h"
//#include "air_ticket.h"
void searchbyEndPlace()
{
	char endpoint[MAX_END];
	printf("�����뵽����У�\n");
	scanf("%s",endpoint);
	AIRcraft *p = aircraftListHead;
	while(p)
	{

		if(strcmp(p->endpoint,endpoint) == 0 )
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
