//�������ܣ���ʾ����Ķ�Ʊ��Ϣ
//����ѡ����ʾ��һ�����ඩƱ��Ϣ
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
    printf("�������ѯ����ţ�");
    scanf("%s",Airnum);

    AIRcraft *p = aircraftListHead;

    while(p)
    {
		if(strcmp(p->Airnum,Airnum) == 0 )
		{
			if(p->remainder == p->max_pass)
			{
				printf("�ú���û���ÿ�Ԥ��.......\n");
			}
            else
            {   passnum = p->max_pass - p->remainder;
				printf("�ú���һ����%d ���ÿͣ���Ϣ����: \n",passnum);
                printf("�����     ����         ���֤        ��λ�ȼ�      ������     Ŀ�ĵ�      ��������   ����ʱ��     ����ʱ��\n");

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
		printf("�������������.........\n\n");
	}


}
