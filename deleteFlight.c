
//�������ܣ� ɾ������

//δ�жϵ���������Ԥ��ʱ���Ƿ����ɾ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deleteFlight.h"
#include "globals.h"
#include "global_list.h"
//#include "air_ticket.h"
void deleteFlight()
{
    char Airnum[MAX_aircraft_num];
    char c;
    printf("��ȷ��Ҫɾ�������: \n");
    scanf("%s", Airnum);

    printf("�Ƿ�Ҫɾ��������Ϣ(Y/N)?");
    scanf(" %c",&c);
    while(c=='Y' || c== 'y')
    {
       AIRcraft *p = aircraftListHead, *pr=aircraftListHead;
       if(aircraftListHead==NULL)
      {
        printf("����û����Ӻ�����Ϣ,�޷����д˲���\n");
        return;
       }
       while(strcmp(p->Airnum,Airnum) != 0 && p->airnext!=NULL )
       {
        pr=p;
        p=p->airnext;//δ�ҵ���δ����β�������ƶ�
       }
       if(strcmp(p->Airnum,Airnum)==0)//�ҵ�Ҫɾ���ĺ���
      {
          if(p==aircraftListHead)
          {
            aircraftListHead=p->airnext;
           }
          else
          {
            pr->airnext=p->airnext;
           }
          free(p);
          acount--;
          printf("ɾ���ɹ�\n");
          if(acount==0)
          {
              printf("��ɾ��ȫ������\n");
              return;
          }
       }
       else
       {
         printf("δ�ҵ��κ�����Ϣ\n");
        }
        printf("�Ƿ�Ҫɾ������������Ϣ(Y/N)?");
        scanf(" %c",&c);
        if(c=='Y' || c== 'y')
        {
            printf("����������Ҫɾ���ĺ����: \n");
            scanf("%s", Airnum);
        }
    }
}
