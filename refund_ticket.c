#include <stdio.h>
/*������Ʊҵ��*/
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
                    printf("���ٴ�ȷʵ�Ƿ�Ҫ������Ʊ(y/n)?\n");
                    scanf("%c",&choose);
                    if(choose=='Y'|| choose=='y')
                    {
                        if(i== ticket-1)//�ж��Ƿ�Ϊ���һ��
                        {
                            memset(&p->passenger[i], 0, sizeof(p->passenger));
                        }
                        else
                        {
                            for(int j=i;j<ticket-1;j++)
                            {
                                p->passenger[j]=p->passenger[j+1];//���һ�������ǰ���ֵַ�Ĳ����������ṹ�����飬��������ִ���������׵�ַ
                            }
                            p->remainder++;
                            printf("��Ʊ�ɹ���\n");
                        }

                    }
                    else
                    {
                        printf("����������һ����\n");
                    }
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
