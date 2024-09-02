
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

//1.��Ʊ�ͻ�����Ϣ�ṹ��
typedef struct Book
{
	char Airnum[MAX_aircraft_num];//Ԥ�������
	char name[NAME];//�ͻ�����
	char didentify[DID];//���֤��
	int  grade;//��λ�ȼ�
	char start[MAX_start];//������
	char endpoint[MAX_END];//Ŀ�ĵ�
	char dates[DATE_LENGTH];//��������
    char gotime[TIME];//����ʱ��
    char gettime[TIME];//����ʱ��
    //int  ticketnum;//һ�����ID����ֻ�ܶ�һ��Ʊ
	//struct Book *Passnext;//ָ����һ���û����׵�ַ
	//struct aircraft *aircraftList;//Ԥ�������б�
}BookList, *PBookList;


//2. ������Ϣ�ṹ��
typedef struct aircraft{
    char Airnum[MAX_aircraft_num];//�����
    char start[MAX_start];//������
    char endpoint[MAX_END];//Ŀ�ĵ�
    char dates[DATE_LENGTH];//��������
    char gotime[TIME];//����ʱ��
    char gettime[TIME];//����ʱ��
    char mode[MODE];//����
    int max_pass;//�˿Ͷ���(����ؿ���)
    int remainder;//������λ(��Ʊ)
    float price;//Ʊ��
    struct Book passenger[MAXBOOK];
    struct aircraft *airnext;
    //PBookList headpointer;//ָ���Ա���������ͷָ�룬ͨ�����ָ��Ϳ����ҵ����г˿͵�������
} AIRcraft,*PAIRcraft;

/*
//������Ϣ����ṹ�壬��������ʽ�洢
struct air_info_link
{
	AIRcraft Aircraft; //������Ϣ�ṹ��
	struct air_info_link *airnext;//ָ����һ��������Ϣ
};

//�����ͻ�����ṹ�壬��������ʽ�洢
 struct bookinfo_link
   {
	BookList book;
	struct bookinfo_link *booknext;//ָ����һ�������ͻ�
   };
*/
#endif // LIST_NODE_H
