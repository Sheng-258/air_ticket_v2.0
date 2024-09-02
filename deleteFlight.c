
//函数功能： 删除航班

//未判断当航班有人预定时，是否可以删除
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deleteFlight.h"
#include "globals.h"
#include "global_list.h"
//#include "air_ticket.h"
void deleteFlight()
{
    char Airnum[MAX_aircraft_num];
    char c;
    printf("请确认要删除航班号: \n");
    scanf("%s", Airnum);

    printf("是否要删除航班信息(Y/N)?");
    scanf(" %c",&c);
    while(c=='Y' || c== 'y')
    {
       AIRcraft *p = aircraftListHead, *pr=aircraftListHead;
       if(aircraftListHead==NULL)
      {
        printf("您还没有添加航班信息,无法进行此操作\n");
        return;
       }
       while(strcmp(p->Airnum,Airnum) != 0 && p->airnext!=NULL )
       {
        pr=p;
        p=p->airnext;//未找到且未到表尾，继续移动
       }
       if(strcmp(p->Airnum,Airnum)==0)//找到要删除的航班
      {
          if(p==aircraftListHead)
          {
            aircraftListHead=p->airnext;
           }
          else
          {
            pr->airnext=p->airnext;
           }
          free(p);
          acount--;
          printf("删除成功\n");
          if(acount==0)
          {
              printf("已删除全部航班\n");
              return;
          }
       }
       else
       {
         printf("未找到次航班信息\n");
        }
        printf("是否要删除继续航班信息(Y/N)?");
        scanf(" %c",&c);
        if(c=='Y' || c== 'y')
        {
            printf("请重新输入要删除的航班号: \n");
            scanf("%s", Airnum);
        }
    }
}
