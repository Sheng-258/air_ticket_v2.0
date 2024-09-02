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
        printf("此时没有航班信息，无法修改\n");
        return;
    }
    char Airnum[MAX_aircraft_num];
    printf("请输入要修改的航班号: \n");
    scanf("%s", Airnum);
    printf("是否要修改航班信息(Y/N)?");
    scanf(" %c",&c);
 while(c=='Y' || c== 'y')
 {
    AIRcraft *p = aircraftListHead, *pr=aircraftListHead;
    while(strcmp(p->Airnum,Airnum) != 0 && p->airnext!=NULL )
    {
        pr=p;
        p=p->airnext;//未找到且未到表尾，继续移动
    }
    if(strcmp(p->Airnum,Airnum)==0)//找到要修改的航班
      {
               while(1)
               {
                printf("*            修改航班信息--子菜单           *\n");
                printf("*            1.修改航班的起飞时间           *\n");
                printf("*            2.修改航班的到达时间           *\n");
                printf("*            3.修改航班的出发城市           *\n");
                printf("*            4.修改航班的到达城市           *\n");
                printf("*            5.修改航班的机票价格           *\n");
                printf("*            6.退出航班信息子菜单           *\n");
                printf("请 选 择(1-6):\n");
                scanf("%d", &subchoice);
                switch (subchoice)
                {
                    case 1:
                        {  printf("请输入要替换的起飞时间：\n");
                           scanf("%s",p->gotime);//char gotime[TIME],scanf("%s",gotime),strcpy(p->Aircraft.gotime,gotime)
                           printf("修改成功\n");
                           break;
                        }
                    case 2:
                        {   printf("请输入要替换的到达时间：\n");
                            scanf("%s",p->gettime);
                            printf("修改成功\n");
                            break;
                        }
                    case 3:
                        {
                            printf("请输入要替换的出发城市：\n");
                            scanf("%s",p->start);
                            printf("修改成功\n");
                            break;
                        }
                    case 4:
                        {
                            printf("请输入要替换的到达城市：\n");
                            scanf("%s",p->endpoint);
                            printf("修改成功\n");
                            break;
                        }
                    case 5:
                        {
                            printf("请输入要替换的机票价格：\n");
                            scanf("%f",&p->price);
                            printf("修改成功\n");
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

    else
       {
         printf("未找到次航班信息\n");
         printf("是否要继续修改航班信息(Y/N)?");
         scanf(" %c",&c);
         if(c=='Y' || c== 'y')
         {
             printf("请重新输入要修改的航班号: \n");
             scanf("%s", Airnum);
         }

        }

 }
}
