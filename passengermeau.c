#include <stdio.h>
#include "passengermeau.h"


void passengermeau(void)
{
    int subsel,Count=0;
	while (1)
	{
		printf("============================\n");
		printf("=     航空公司乘客系统     =\n");
		printf("============================\n");
		printf("*    1.查询航线信息        *\n");
		printf("*    2.订票                *\n");
		printf("*    3.退票                *\n");
		printf("*    4.查询订票信息        *\n");
		printf("*    5.退出                *\n");
		printf("============================\n");
		printf("请 选 择(1-5):\n");
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
                   printf("输入错误 %d 次，请重新输入\n",Count);
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
