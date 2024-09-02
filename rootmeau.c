//函数功能：显示管理员系统界面
//函数参数：无
//函数返回：无

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
	//设置试错机会次数
	int times = 3;
	while(1)
    {
		printf("请输入管理员账号admin：");
		scanf("%s",account);
		printf("请输入管理员密码123456：");
		scanf("%s",password);
		times--;
		//判断用户名和密码是否输入正确
		if(!strcmp(account,ManagerAccount) && !strcmp(password,ManagerPassword)){
			printf("输入正确！ 即将进入管理员菜单界面 > >\n");
			system("pause");
			system("cls");
			break;
		}else if(times >= 1){
			printf("账号或密码错误，您还有%d次机会\n\n",times);
		}else{
			printf("抱歉！试错机会已用完，即将返回主界面......\n");
			system("pause");
			system("cls");
			return;
		}
	}
	while (1)
	{
		printf("============================\n");
		printf("=   航空公司管理员系统     =\n");
		printf("============================\n");
		printf("*    1.增加航班            *\n");
		printf("*    2.删除航班            *\n");
		printf("*    3.显示航班的订票信息  *\n");
		printf("*    4.修改航班信息        *\n");
		printf("*    5.退出                *\n");
		printf("============================\n");
		printf("请 选 择(1-5):\n");
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
                   printf("输入错误, 还有 %d 次机会，请重新输入\n",3-Count);//“3”是最多错误尝试次数
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
