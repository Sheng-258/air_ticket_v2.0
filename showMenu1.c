//showMenu1.c
//�������ܣ���ʾ���˵�
//������������
//��������ֵ����
#include <stdio.h>
#include "showMenu1.h"
#include "rootmeau.h"
#include "passengermeau.h"
#include <stdlib.h>
//#include "air_ticket.h"
void showMenu1()
{
    int choice,Count=0;
    while(1)
    {
        printf("\n");
        printf("\t��ӭ����xx���ն�Ʊϵͳ\n");
        printf("*****************************\n");
        printf("*       ���ն�Ʊ����ϵͳ    *\n");
        printf("*        1�����չ���Ա      *\n");
        printf("*        2���˿�            *\n");
        printf("*        3���˳�            *\n");
        printf("�� ѡ ��(1-3):\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:{rootmeau(); break;}//����Ա
		case 2:{passengermeau(); break;}//�˿�
		case 3:{printf("��ӭ�´��ٴ�ʹ��\n");exit(0);}//�˳�����
		default:
		    {  Count++;
		       if(Count<3)
               {
                   printf("������󣬻��� %d �λ��ᣬ����������\n",3-Count);
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
