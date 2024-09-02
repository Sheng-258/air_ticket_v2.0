
#ifndef LIST_NODE_H
#define LIST_NODE_H

#define MAX_aircraft_num 20
#define MAX_start 20
#define MAX_END 20
#define DATE_LENGTH 10
#define TIME 6
#define MODE 5

#define NAME 20
#define DID 18

#define MAXAIR  20
#define MAXBOOK  100

//1.订票客户的信息结构体
typedef struct Book
{
	char Airnum[MAX_aircraft_num];//预定航班号
	char name[NAME];//客户姓名
	char didentify[DID];//身份证号
	int  grade;//座位等级
	char start[MAX_start];//出发地
	char endpoint[MAX_END];//目的地
	char dates[DATE_LENGTH];//飞行日期
    char gotime[TIME];//出发时间
    char gettime[TIME];//到达时间
    //int  ticketnum;//一个身份ID限制只能订一张票
	//struct Book *Passnext;//指向下一个用户的首地址
	//struct aircraft *aircraftList;//预定航班列表
}BookList, *PBookList;


//2. 航班信息结构体
typedef struct aircraft{
    char Airnum[MAX_aircraft_num];//航班号
    char start[MAX_start];//出发地
    char endpoint[MAX_END];//目的地
    char dates[DATE_LENGTH];//飞行日期
    char gotime[TIME];//出发时间
    char gettime[TIME];//到达时间
    char mode[MODE];//机型
    int max_pass;//乘客定额(最大载客量)
    int remainder;//可用座位(余票)
    float price;//票价
    struct Book passenger[MAXBOOK];
    struct aircraft *airnext;
    //PBookList headpointer;//指向乘员名单链表的头指针，通过这个指针就可以找到所有乘客的名单了
} AIRcraft,*PAIRcraft;

/*
//航班信息总体结构体，以链表形式存储
struct air_info_link
{
	AIRcraft Aircraft; //航班信息结构体
	struct air_info_link *airnext;//指向下一个航班信息
};

//订单客户总体结构体，以链表形式存储
 struct bookinfo_link
   {
	BookList book;
	struct bookinfo_link *booknext;//指向下一个订单客户
   };
*/
#endif // LIST_NODE_H
