#include <stdio.h>
#include "searchbyAirnumber.h"
#include "searchbystartPlace.h"
#include "searchbyEndPlace.h"

void CheckRouteInformation(void)
{
	int subsel,Count=0;
	while (1)
	{
		printf("============================\n");
		printf("=       ��ѯ������Ϣ       =\n");
		printf("============================\n");
		printf("*      1.������Ų�ѯ      *\n");
		printf("*      2.�����վ��ѯ      *\n");
		printf("*      3.���յ�վ��ѯ      *\n");
		printf("*      4.�������˵�        *\n");
		printf("============================\n");
		printf("�� ѡ ��(1-4):\n");
		scanf("%d", &subsel);
		switch (subsel)
		{
		case 1:searchbyAirnumber(); break;
		case 2:searchbystartPlace(); break;
		case 3:searchbyEndPlace(); break;
		case 4:return;
		default:
		    {  Count++;
		       if(Count<2)
               {
                   printf("�������,���� %d �Σ�����������\n",3-Count);
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
