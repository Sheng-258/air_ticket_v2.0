//�������ܣ���ʾ����Աϵͳ����
//������������
//�������أ���

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "addFlight.h"
//#include "deleteFlight.h"
//#include "printOrderCustomByAirNum1.h"
//#include "ModifyFlightInformation.h"
#include "rootmeau.h"
//#include "air_ticket.h"
void rootmeau(void)
{
    int subchoice,Count=0;
    char account[32];
	char password[20];
	//�����Դ�������
	int times = 3;
	while(1)
    {
		printf("���������Ա�˺�admin��");
		scanf("%s",account);
		printf("���������Ա����123456��");
		scanf("%s",password);
		times--;
		//�ж��û����������Ƿ�������ȷ
		if(!strcmp(account,ManagerAccount) && !strcmp(password,ManagerPassword)){
			printf("������ȷ�� �����������Ա�˵����� > >\n");
			system("pause");
			system("cls");
			break;
		}else if(times >= 1){
			printf("�˺Ż��������������%d�λ���\n\n",times);
		}else{
			printf("��Ǹ���Դ���������꣬��������������......\n");
			system("pause");
			system("cls");
			return;
		}
	}
	while (1)
	{
		printf("============================\n");
		printf("=   ���չ�˾����Աϵͳ     =\n");
		printf("============================\n");
		printf("*    1.���Ӻ���            *\n");
		printf("*    2.ɾ������            *\n");
		printf("*    3.��ʾ����Ķ�Ʊ��Ϣ  *\n");
		printf("*    4.�޸ĺ�����Ϣ        *\n");
		printf("*    5.�˳�                *\n");
		printf("============================\n");
		printf("�� ѡ ��(1-5):\n");
		scanf("%d", &subchoice);
		switch (subchoice)
		{
		case 1:addFlight(); break;
		case 2:deleteFlight(); break;
		case 3:printOrderCustomByAirNum1(); break;
		case 4:ModifyFlightInformation(); break;
		case 5:return;
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
