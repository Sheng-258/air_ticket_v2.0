//�������ܣ���Ӻ���,�����ټ��жϺ�����Ϣ�Ƿ��ظ�����
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
        printf("������Ӻ�����Ϣ���Ѵﵽ��󺽰�����\n");
        return;
    }
    else
    {
        printf("�Ƿ�Ҫ��Ӻ�����Ϣ(Y/N)?");
        scanf(" %c",&c);
        while(c=='Y' || c== 'y')
        {
            AIRcraft *p = NULL;

            p = (AIRcraft *)malloc(sizeof(AIRcraft));
            if (p==NULL)
            {
            printf("�ڴ����ʧ�ܣ�����ϵϵͳ����Ա! \n");
            exit(0);
            }
            printf("�����뺽����Ϣ��\n");
            printf("����ţ�");
            scanf("%s",p->Airnum);//����˷������ԣ�����strcpy
            printf("�����أ�");
            scanf("%s",p->start);
            printf("Ŀ�ĵأ�");
            scanf("%s",p->endpoint);
            printf("�������ڣ�");
            scanf("%s",p->dates);
            printf("����ʱ�䣺");
            scanf("%s",p->gotime);
            printf("����ʱ�䣺");
            scanf("%s",p->gettime);
            printf("���ͣ�");
            scanf("%s",p->mode);
            printf("�˿Ͷ��");
            scanf("%d",&p->max_pass);
            printf("��Ʊ��");
            scanf("%d",&p->remainder);
            printf("�۸�");
            scanf("%f",&p->price);
            p->airnext = NULL;


            if(aircraftListHead==NULL)
            {
                aircraftListHead=p;//�½��Ľڵ�(������Ϣ����ڵ�)Ϊͷ�ڵ�
            }
            else
            {   AIRcraft *pr = aircraftListHead;
                while(pr->airnext != NULL)//��Ϊ�ƶ�����β��������ƶ�
                {
                    pr=pr->airnext;
                }
                pr->airnext = p;
            }

            i++;
            acount++;
            if (acount >= MAXAIR)
            {
              printf("��������Ӻ�����Ϣ���Ѵﵽ��󺽰�����\n");
              return;
            }
            else
            {
               printf("�Ƿ�Ҫ������Ӻ�����Ϣ(Y/N)?");
               scanf(" %c",&c);
            }


        }

       printf("������� %d ��������Ϣ��\n",i);

    }

}
