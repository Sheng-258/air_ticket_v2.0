#include <stdio.h>
#include "passengermeau.h"


void passengermeau(void)
{
    int subsel,Count=0;
	while (1)
	{
		printf("============================\n");
		printf("=     ���չ�˾�˿�ϵͳ     =\n");
		printf("============================\n");
		printf("*    1.��ѯ������Ϣ        *\n");
		printf("*    2.��Ʊ                *\n");
		printf("*    3.��Ʊ                *\n");
		printf("*    4.��ѯ��Ʊ��Ϣ        *\n");
		printf("*    5.�˳�                *\n");
		printf("============================\n");
		printf("�� ѡ ��(1-5):\n");
		scanf("%d", &subsel);
		switch (subsel)
		{
		case 1:CheckRouteInformation(); break;
		case 2:orderTicket(); break;
		case 3:refund_ticket(); break;
		case 4:CheckBookingInformation(); break;
		case 5:return;
		default:
		    {  Count++;
		       if(Count<2)
               {
                   printf("������� %d �Σ�����������\n",Count);
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
