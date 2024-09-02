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
		printf("=       查询航线信息       =\n");
		printf("============================\n");
		printf("*      1.按航班号查询      *\n");
		printf("*      2.按起点站查询      *\n");
		printf("*      3.按终点站查询      *\n");
		printf("*      4.返回主菜单        *\n");
		printf("============================\n");
		printf("请 选 择(1-4):\n");
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
                   printf("输入错误,还有 %d 次，请重新输入\n",3-Count);
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
