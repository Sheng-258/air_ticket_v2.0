#include <stdio.h>
#include <string.h>
#include "global_list.h"
#include "globals.h"
#include "orderTicket.h"

/*����Ʊҵ��*/
void orderTicket()
{
	int choose;
	char airnum[MAX_aircraft_num];
	printf("\n *****�˿Ͷ�Ʊϵͳ*******\n");
	printf("\t\t 1��ѡ�񺽰ඩƱ\n");
	printf("\t\t 2��������һ��\n");
	printf("\n*************************\n");
	printf("��ѡ��");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			   if(acount==0)
               {
                   printf("�Բ���������ԭ�����к���ͣ��\n");
                   break;
               }
			   AIRcraft *p =aircraftListHead;
			   printf("\n ********ȫ���ĺ�����Ϣ*******\n");
			   printf("�����     ������     Ŀ�ĵ�    �������    ����ʱ��   ����ʱ��     ����     �˿Ͷ���    ��Ʊ    Ʊ��\n");
			   while(p)
               {
                printf("%s        %s          %s       %s          %s         %s           %s       %d          %d       %f\n",p->Airnum,p->start,p->endpoint,p->dates,p->gotime,p->gettime,p->mode,p->max_pass,p->remainder,p->price);
                p=p->airnext;

               }
               printf("��������ҪԤ���ĺ���ţ�");
               scanf("%s",airnum);
               AIRcraft *pr =aircraftListHead;
               while(pr)
               {
                   if(strcmp(pr->Airnum,airnum)==0)
                   {
                       printf("�����     ������     Ŀ�ĵ�    �������    ����ʱ��   ����ʱ��     ����    Ʊ��\n");
                       printf("%s         %s         %s        %s          %s         %s           %s      %d",pr->Airnum,pr->start,pr->endpoint,pr->dates,pr->gotime,pr->gettime,pr->mode,pr->price);
                       printf("ȷ�Ϲ�Ʊ��(y/n) :");
                       char sel;
                       scanf("%c",&sel);
                       if(sel=='y'|| sel=='Y')
                       {
                           if(pr->remainder==0)
                           {
                               printf("��Ǹ���˺����Ʊ������\n");

                           }
                           else
                           {   if(pr->max_pass - pr->remainder != MAXBOOK)
                               {
                                 printf("������������Ϣ��\n");
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].Airnum,airnum);
                                 printf("������\n");
                                 scanf("%s",pr->passenger[pr->max_pass - pr->remainder].name);
                                 printf("���֤�ţ�\n");
                                 scanf("%s",pr->passenger[pr->max_pass - pr->remainder].didentify);
                                 printf("��λ�ȼ���\n");
                                 scanf("%d",&pr->passenger[pr->max_pass - pr->remainder].grade);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].start,pr->start);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].endpoint,pr->endpoint);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].dates,pr->dates);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].gotime,pr->gotime);
                                 strcpy(pr->passenger[pr->max_pass - pr->remainder].gettime,pr->gettime);
                               }
                               pr->remainder--;
                               printf("��ϲ��Ʊ�ɹ���\n");
                           }
                       }
                       else
                       {
                           printf("�����˳���\n");
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
		         printf("��Ǹ��û�в�ѯ��Ӧ�ĺ���...\n");
	            }
			break;
		case 2:
			return;
	}

}
