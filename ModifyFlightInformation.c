#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ModifyFlightInformation.h"
#include "globals.h"
#include "global_list.h"
//#include "air_ticket.h"
void ModifyFlightInformation()
{
    int subchoice,Count=0;
    char c;
    if (acount == 0)
    {
        printf("��ʱû�к�����Ϣ���޷��޸�\n");
        return;
    }
    char Airnum[MAX_aircraft_num];
    printf("������Ҫ�޸ĵĺ����: \n");
    scanf("%s", Airnum);
    printf("�Ƿ�Ҫ�޸ĺ�����Ϣ(Y/N)?");
    scanf(" %c",&c);
 while(c=='Y' || c== 'y')
 {
    AIRcraft *p = aircraftListHead, *pr=aircraftListHead;
    while(strcmp(p->Airnum,Airnum) != 0 && p->airnext!=NULL )
    {
        pr=p;
        p=p->airnext;//δ�ҵ���δ����β�������ƶ�
    }
    if(strcmp(p->Airnum,Airnum)==0)//�ҵ�Ҫ�޸ĵĺ���
      {
               while(1)
               {
                printf("*            �޸ĺ�����Ϣ--�Ӳ˵�           *\n");
                printf("*            1.�޸ĺ�������ʱ��           *\n");
                printf("*            2.�޸ĺ���ĵ���ʱ��           *\n");
                printf("*            3.�޸ĺ���ĳ�������           *\n");
                printf("*            4.�޸ĺ���ĵ������           *\n");
                printf("*            5.�޸ĺ���Ļ�Ʊ�۸�           *\n");
                printf("*            6.�˳�������Ϣ�Ӳ˵�           *\n");
                printf("�� ѡ ��(1-6):\n");
                scanf("%d", &subchoice);
                switch (subchoice)
                {
                    case 1:
                        {  printf("������Ҫ�滻�����ʱ�䣺\n");
                           scanf("%s",p->gotime);//char gotime[TIME],scanf("%s",gotime),strcpy(p->Aircraft.gotime,gotime)
                           printf("�޸ĳɹ�\n");
                           break;
                        }
                    case 2:
                        {   printf("������Ҫ�滻�ĵ���ʱ�䣺\n");
                            scanf("%s",p->gettime);
                            printf("�޸ĳɹ�\n");
                            break;
                        }
                    case 3:
                        {
                            printf("������Ҫ�滻�ĳ������У�\n");
                            scanf("%s",p->start);
                            printf("�޸ĳɹ�\n");
                            break;
                        }
                    case 4:
                        {
                            printf("������Ҫ�滻�ĵ�����У�\n");
                            scanf("%s",p->endpoint);
                            printf("�޸ĳɹ�\n");
                            break;
                        }
                    case 5:
                        {
                            printf("������Ҫ�滻�Ļ�Ʊ�۸�\n");
                            scanf("%f",&p->price);
                            printf("�޸ĳɹ�\n");
                            break;
                        }
                    case 6:
                        {
                            return;
                        }
                    default:
                            {  Count++;
                                if(Count<3)
                                {
                                    printf("�������, ���� %d �λ��ᣬ����������\n",3-Count);//��3�����������Դ���
                                }
                                else
                                {
                                    return;
                                }
                                break;
                            }
                }
              }
        }

    else
       {
         printf("δ�ҵ��κ�����Ϣ\n");
         printf("�Ƿ�Ҫ�����޸ĺ�����Ϣ(Y/N)?");
         scanf(" %c",&c);
         if(c=='Y' || c== 'y')
         {
             printf("����������Ҫ�޸ĵĺ����: \n");
             scanf("%s", Airnum);
         }

        }

 }
}
