//��ѯ��Ʊ��Ϣ
#include <stdio.h>
#include "refund_ticket.h"
#include "global_list.h"
#include <string.h>
#include "CheckBookingInformation.h"
void CheckBookingInformation()
{
    char airnum[MAX_aircraft_num];
	char Name[NAME];
	char Didentify[DID];
	int ticket;

    printf("��������Ԥ���ĺ���ţ�\n");
    scanf("%s",airnum);
    AIRcraft *p =aircraftListHead;
    while(p)
    {
        if(strcmp(p->Airnum,airnum)==0)
        {
            printf("�������������֣�\n");
            scanf("%s",Name);
            printf("�������������֤�ţ�\n");
            scanf("%s",Didentify);
            ticket=p->max_pass - p->remainder;
            for(int i=0;i<ticket;i++)
            {
                if(strcmp(p->passenger[i].name,Name)==0 && strcmp(p->passenger[i].didentify,Didentify)==0)
                {
                      printf("���Ķ�Ʊ��Ϣ��\n");
                      printf("����ţ�%s\n",p->Airnum);
                      printf("������%s\n",p->passenger[i].name);
                      printf("���֤�ţ�%s\n",p->passenger[i].didentify);
                      printf("��λ�ȼ���%d\n",p->passenger[i].grade);
                      printf("�����أ�%s\n",p->start);
                      printf("Ŀ�ĵأ�%s\n",p->endpoint);
                      printf("�������ڣ�%s\n",p->dates);
                      printf("����ʱ�䣺%s\n",p->gotime);
                      printf("����ʱ�䣺%s\n",p->gettime);
                      printf("���ͣ�%s\n",p->mode);
                      printf("Ʊ�ۣ�%f\n",p->price);
                      printf("����������һ��(y/n)��\n");
                      return;
                }

            }
            printf("��Ǹ����������Ϣ����δ�ҵ���Ӧ�˿���Ϣ,����������һ��\n");
            return;

        }
        p=p->airnext;
    }
    printf("��Ǹ�������뺽������󣬻���û�д˺�����Ϣ\n");
}
