#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<windows.h>
#include<ctype.h>

struct time{
	int year;
	int month;
	int day;
};
typedef struct library{
	long booknum;
	char bookname[20];
	char author[20];
	int speciesnumber;
	char publishers[30];
	struct time publish_time;
	float price;
	struct library *next;
}*Booklist,BOOK;

int count;
Booklist lHead;
/******************************************************/
void deletebook();
void changebook();
void searchbook_num();
void searchbook_name();
void searchbook_author();
void searchbook_speciesnumber();
void searchbook_publisher();
void searchbook();
void addbooks();
void readfile();
void savefile();
Booklist inputbooks();
void outputbooks();
void printscreen2();
void printscreen1();
void printscreen0();
/******************************************************/

/* ������ */
int main()
{    
    printscreen0();
	return 0;
}
/* ������ */
void printscreen0()
{
	char choice='1';
	while(choice!='0'){
	    system("cls");
	    printf("\t********************************************\n\n");
		printf("\t            ��ӭ����ͼ�����ϵͳ\n\n");
	    printf("\t       ====     1.  ����ͼ��     ====\n\n");
		printf("\t       ====     2.  ��ȡ�ļ�     ====\n\n");
		printf("\t       ====     3.  �����ļ�     ====\n\n");
	    printf("\t       ====     0.    �˳�       ====\n\n");
	    printf("\t********************************************\n\n");
        printf("\t         (��������ѡ��Ҫ���еĲ���!)\n");
    	if( (choice=getche()) != '0' )
	    switch(choice){
            case '1':    printscreen1();    break;
	        case '2':    readfile();    break;
			case '3':    savefile();    break;
	        default:     break;
		}
	}
}
/* ͼ����Ϣ������� */
void printscreen1()   
{
	char choice='1';
	while(choice!='0'){
	   system("cls");
	    printf("\t********************************************\n\n");
	    printf("\t          ��ӭ����ͼ����Ϣ����ϵͳ\n\n");
        printf("\t      ====     1.  �鿴ͼ��       ====\n\n");
        printf("\t      ====     2.    ����         ====\n\n");
        printf("\t      ====     3.���ͼ����Ϣ     ====\n\n");
		printf("\t      ====     4.�޸�ͼ����Ϣ     ====\n\n");
	    printf("\t      ====     5.ɾ��ͼ����Ϣ     ====\n\n");
        printf("\t      ====     6.¼��ͼ����Ϣ     ====\n\n");
	    printf("\t      ====     0.    �˳�         ====\n\n");
     	printf("\t*******************************************\n\n");
        printf("\t         (��������ѡ��Ҫ���еĲ���!)\n");
	    if( (choice=getche()) != '0' )
        switch(choice){
	        case '1':    outputbooks();    break;
	        case '2':    searchbook();     break;
	        case '3':    addbooks();    break;
	        case '4':    changebook();    break;
			case '5':    deletebook();    break;
			case '6':    lHead=inputbooks();    break;
	        default:     break;
		}
	}
}
/* �鿴ͼ�� */
void outputbooks()
{
     Booklist pTemp;
	 pTemp=lHead;
	 system("cls");
	 printf("\t************����%d����************\n\n",count);
	 int index=1;
	 while(pTemp!=NULL){
		printf("\t------------��%d����-----------\n\n",index);
        printf("\tͼ���:  %08ld",pTemp->booknum);
	    printf("\n\tͼ����:  %s",pTemp->bookname);
	    printf("\n\t����:  %s",pTemp->author);
	    printf("\n\tͼ��������:  %03d",pTemp->speciesnumber);
	    printf("\n\t������:  %s",pTemp->publishers);
	    printf("\n\t����ʱ��:  ");
	    printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                 pTemp->publish_time.month,
			    		 pTemp->publish_time.day);
        printf("\n\t�۸�:  %.2f",pTemp->price);
        printf("\n\n\t-------------------------------\n\n");
		pTemp=pTemp->next;
		index++;
	 }
	 printf("�����������!\n"); 
	 getch();
}
/* ���� */
void searchbook()
{
	while(1){
	    system("cls");
	    printf("\t\t��ѡ��������ʽ:\n\n");
	    printf("\t\t  *********  1-ͼ���\n\n"); 
	    printf("\t\t  *********  2-ͼ����\n\n"); 
	    printf("\t\t  *********  3-����\n\n"); 
	    printf("\t\t  *********  4-������\n\n"); 
	    printf("\t\t  *********  5-ͼ�����ͺ�\n\n");
	    printf("\t\t  *********  0-�˳�\n\n");
	    printf("\t\t  ----------------��ѡ��:");
	    int choice=1;
	    scanf("%d",&choice);
	    switch(choice){
		    case 1:  searchbook_num();    break;
		    case 2:  searchbook_name();   break;
		    case 3:  searchbook_author();    break;
		    case 4:  searchbook_publisher();    break;
		    case 5:  searchbook_speciesnumber();    break;
		    case 0:  return;
	        default:   break; 
	    }
	}
}
/* ��ͼ������� */
void searchbook_num()
{
	int book_num;
	int index=0;
	printf("\n\t\t*********������ͼ���:");
	scanf("%d",&book_num);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(pTemp->booknum==book_num){
			printf("\n\t\t******************\n\n");
			printf("\t\tͼ���:  %08ld",pTemp->booknum);
	        printf("\n\t\tͼ����:  %s",pTemp->bookname);
	        printf("\n\t\t����:  %s",pTemp->author);
	        printf("\n\t\tͼ��������:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t������:  %s",pTemp->publishers);
	        printf("\n\t\t����ʱ��:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t�۸�:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  δ�ҵ�ͼ��!");
	printf("\t\t-----  �����������...");
    getch();
}
/* ��ͼ�������� */
void searchbook_name()
{
	char book_name[20];
	int index=0;
	printf("\n\t\t*********������ͼ����:");
	fflush(stdin);
	gets(book_name);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(strcmp(book_name,pTemp->bookname)==0){
			printf("\n\t\t******************\n\n");
			printf("\t\tͼ���:  %08ld",pTemp->booknum);
	        printf("\n\t\tͼ����:  %s",pTemp->bookname);
	        printf("\n\t\t����:  %s",pTemp->author);
	        printf("\n\t\tͼ��������:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t������:  %s",pTemp->publishers);
	        printf("\n\t\t����ʱ��:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t�۸�:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  δ�ҵ�ͼ��!");
	printf("\t\t-----  �����������...");
	getch();
}
/* ���������� */
void searchbook_author()
{
	char book_author[20];
	int index=0;
	printf("\n\t\t*********����������:");
	fflush(stdin);
	gets(book_author);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(strcmp(book_author,pTemp->author)==0){
			printf("\n\t\t******************\n\n");
			printf("\t\tͼ���:  %08ld",pTemp->booknum);
	        printf("\n\t\tͼ����:  %s",pTemp->bookname);
	        printf("\n\t\t����:  %s",pTemp->author);
	        printf("\n\t\tͼ��������:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t������:  %s",pTemp->publishers);
	        printf("\n\t\t����ʱ��:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t�۸�:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  δ�ҵ�ͼ��!");
	printf("\t\t-----  �����������...");
    getch();
}
/* ��ͼ�����ͺ����� */
void searchbook_speciesnumber()
{
	int book_speciesnumber;
	int index=0;
	printf("\n\t\t*********������ͼ�����ͺ�:");
	scanf("%d",&book_speciesnumber);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(pTemp->speciesnumber==book_speciesnumber){
			printf("\n\t\t******************\n\n");
			printf("\t\tͼ���:  %08ld",pTemp->booknum);
	        printf("\n\t\tͼ����:  %s",pTemp->bookname);
	        printf("\n\t\t����:  %s",pTemp->author);
	        printf("\n\t\tͼ��������:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t������:  %s",pTemp->publishers);
	        printf("\n\t\t����ʱ��:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t�۸�:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  δ�ҵ�ͼ��!");
	printf("\t\t-----  �����������...");
    getch();
}
/* ������������ */
void searchbook_publisher()
{
	char book_publisher[30];
	int index=0;
	printf("\n\t\t*********�����������:");
	fflush(stdin);
	gets(book_publisher);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(strcmp(book_publisher,pTemp->publishers)==0){
			printf("\n\t\t******************\n\n");
			printf("\t\tͼ���:  %08ld",pTemp->booknum);
	        printf("\n\t\tͼ����:  %s",pTemp->bookname);
	        printf("\n\t\t����:  %s",pTemp->author);
	        printf("\n\t\tͼ��������:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t������:  %s",pTemp->publishers);
	        printf("\n\t\t����ʱ��:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t�۸�:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  δ�ҵ�ͼ��!");
	printf("\t\t-----  �����������...");
    getch();
}
/* ���ͼ����Ϣ */
void addbooks()
{
	system("cls");
	char ch='Y';
	Booklist pTemp,pPre;
	pTemp=lHead;
	for(int i=0;i<count-1;i++)
		pTemp=pTemp->next;
	pPre=pTemp;
	while(toupper(ch)=='Y'){
	    pTemp=(Booklist)malloc(sizeof(BOOK));
	    printf("\n\t------------��%d����-----------\n\n",count+1);
        printf("\tͼ���:  ");
	    scanf("%ld",&pTemp->booknum);
		fflush(stdin);
	    printf("\n\tͼ����:  ");
	    gets(pTemp->bookname);
	    printf("\n\t����:  ");
	    gets(pTemp->author);
	    printf("\n\tͼ��������:  ");
	    scanf("%d",&pTemp->speciesnumber);
		fflush(stdin);
	    printf("\n\t������:  ");
	    gets(pTemp->publishers);
	    printf("\n\t����ʱ��:  ");
	    scanf("%d-%d-%d",&pTemp->publish_time.year,
		                 &pTemp->publish_time.month,
			    		 &pTemp->publish_time.day);
        printf("\n\t�۸�:  ");
	    scanf("%f",&pTemp->price);
        printf("\n\n\t-------------------------------\n\n");
        pTemp->next=NULL;
	    pPre->next=pTemp;
	    pPre=pTemp;
	    count++;
	    printf("\t�Ƿ�������(Y/N):");
			ch=getche();
	}
}
/* �޸�ͼ����Ϣ */
void changebook()
{
	Booklist pTemp;
	pTemp=lHead;
	system("cls");
	printf("\n\t\t*********  �޸Ĳ���\n");
	int book_num;
	printf("\n\t\t-----������ͼ���:");
	scanf("%d",&book_num);
	while(pTemp->booknum!=book_num){
		if(pTemp->next==NULL){
		    printf("\n\t\t-----  δ�ҵ�ͼ��!��������˳�...\n");
		    getch();
		    return;
    	}      
    	pTemp=pTemp->next;
	}
	printf("\n\t\t******************\n\n");
	printf("\t\tͼ���:  %08ld",pTemp->booknum);
    printf("\n\t\tͼ����:  %s",pTemp->bookname);
    printf("\n\t\t����:  %s",pTemp->author);
	printf("\n\t\tͼ��������:  %03d",pTemp->speciesnumber);
	printf("\n\t\t������:  %s",pTemp->publishers);
	printf("\n\t\t����ʱ��:  ");
	printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
    printf("\n\t\t�۸�:  %.2f",pTemp->price);
    printf("\n\n\t\t-------------------------------\n\n");
    printf("\t\t  *********  1-ͼ���\n\n"); 
	printf("\t\t  *********  2-ͼ����\n\n"); 
    printf("\t\t  *********  3-����\n\n"); 
	printf("\t\t  *********  4-������\n\n"); 
	printf("\t\t  *********  5-ͼ�����ͺ�\n\n");
	printf("\t\t  *********  6-����ʱ��\n\n");
	printf("\t\t  *********  7-�۸�\n\n");
	printf("\t\t  *********  0-�˳�\n\n");
	while(1){
	    printf("\t\t  ----------------��ѡ��Ҫ�޸ĵ���Ŀ:");
	    int choice;
        scanf("%d",&choice);
        switch(choice){
    	    case 1:  printf("\t\tͼ���:  ");
		             scanf("%d",&pTemp->booknum);    break;
    	    case 2:  printf("\t\tͼ����:  "); 
		             fflush(stdin);  gets(pTemp->bookname);    break;
    	    case 3:  printf("\t\t����:  ");
		             fflush(stdin);  gets(pTemp->author);    break;
    	    case 4:  printf("\t\tͼ��������:  ");
		             scanf("%d",&pTemp->speciesnumber);    break;
	        case 5:  printf("\t\t������:  ");
		             fflush(stdin);  gets(pTemp->publishers);    break;
		    case 6:  printf("\t\t����ʱ��:  ");
		             scanf("%d-%d-%d",&pTemp->publish_time.year,
					                  &pTemp->publish_time.month, 
									  &pTemp->publish_time.day);    break;
		    case 7:  printf("\t\t�۸�:  ");
		             scanf("%f",&pTemp->price);    break;
		    case 0:  return;
	        default:    break;
	    }
	}
	printf("\n\n\t\t�޸����!��������˳�...\n");
	getch();
} 
/* ɾ��ͼ����Ϣ */
void deletebook()
{
	system("cls");
	int number;
	printf("\n\n\t\t*********ɾ������\n");
	printf("\n\t\tͼ��ţ�");
	scanf("%d",&number); 
	Booklist pTemp,pPre;
	pTemp=lHead;
	pPre=pTemp;
	while(pTemp->booknum!=number){
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	printf("\n\t\t******************\n\n");
	printf("\t\tͼ���:  %08ld",pTemp->booknum);
    printf("\n\t\tͼ����:  %s",pTemp->bookname);
    printf("\n\t\t����:  %s",pTemp->author);
	printf("\n\t\tͼ��������:  %03d",pTemp->speciesnumber);
	printf("\n\t\t������:  %s",pTemp->publishers);
	printf("\n\t\t����ʱ��:  ");
	printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
    printf("\n\t\t�۸�:  %.2f",pTemp->price);
    printf("\n\n\t\t-------------------------------\n\n");
	printf("\t\t*********  ȷ��ɾ��?\n\n");
	printf("\n\t\t  *****  1-ȷ��\n");
	printf("\n\t\t  *****  2-ȡ��\n");
	int choice;
	scanf("%d",&choice);
	if(choice==2)    return;
	if(pTemp->booknum==lHead->booknum)   lHead=lHead->next;
	pPre->next=pTemp->next;
	free(pTemp);
	count--;
	printf("\t\t---------  ɾ���ɹ�!�����������...\n");
	getch();
}
/* ͼ����Ϣ¼�� */
Booklist inputbooks()
{
	Booklist pNew,pEnd,pHead;
	pEnd=NULL;
	pHead=NULL;
	system("cls");
	count=0;
	char ch='Y';
	while(toupper(ch)=='Y'){
		count++;
		pNew=(Booklist)malloc(sizeof(BOOK));
	    printf("\n\t------------��%d����-----------\n\n",count);
        printf("\tͼ���:  ");
	    scanf("%ld",&pNew->booknum);
		fflush(stdin);
	    printf("\n\tͼ����:  ");
	    gets(pNew->bookname);
	    printf("\n\t����:  ");
	    gets(pNew->author);
	    printf("\n\tͼ��������:  ");
	    scanf("%d",&pNew->speciesnumber);
		fflush(stdin);
	    printf("\n\t������:  ");
	    gets(pNew->publishers);
	    printf("\n\t����ʱ��:  ");
	    scanf("%d-%d-%d",&pNew->publish_time.year,
		                 &pNew->publish_time.month,
			    		 &pNew->publish_time.day);
        printf("\n\t�۸�:  ");
	    scanf("%f",&pNew->price);
        printf("\n\n\t-------------------------------\n\n");
		if(count==1){
			pNew->next=pHead;
			pEnd=pNew;
			pHead=pNew;
		}
		else{
		    pNew->next=NULL;
		    pEnd->next=pNew;
		    pEnd=pNew;
		}
		printf("\t�Ƿ����¼��(Y/N):");
		//do{
			ch=getche();
		//}while(toupper(ch)!=('Y'||'N'));
	}    
	return pHead;
}
/* ͼ����Ϣ��ȡ */
void readfile()
{
	FILE *fp;
	fp=fopen("library_list.txt","r");
	if(fp==NULL){
		printf("\n\n\t*******����ļ�������!�봴��!\n");
		return;
	}
	fscanf(fp,"%d",&count);
	int index=0;
	Booklist pTemp,pPre;
	pPre=pTemp=(Booklist)malloc(sizeof(BOOK));
	while(index<count){	
	    index++;
	    fscanf(fp,"%ld %s %s %d %s %d-%d-%d %f\n",&pTemp->booknum,pTemp->bookname,pTemp->author,
		                                &pTemp->speciesnumber,pTemp->publishers,
		                                &pTemp->publish_time.year,&pTemp->publish_time.month,
								        &pTemp->publish_time.day,&pTemp->price);
		if(index==1){
			pTemp->next=NULL;
			pPre=pTemp;
			lHead=pPre;
		}
		else{
			pTemp->next=NULL;
			pPre->next=pTemp;
			pPre=pTemp;
		}
    	pTemp=(Booklist)malloc(sizeof(BOOK));
	}
	free(pTemp); 
	fclose(fp);
	printf("\t��ȡͼ����Ϣ�ɹ�!\n\n");
	printf("\t*************�����������...\n");
	getch();
}
/* ͼ����Ϣ���� */
void savefile()
{
	int choice;
	printf("\n\t\t��ȷ���Ƿ񱣴�?\n");
	printf("\n\t\t  *****  1-ȷ��\n");
	printf("\n\t\t  *****  2-ȡ��\n");
	scanf("%d",&choice);
	if(choice==2)    return;
	FILE *fp;
	Booklist pTemp;
    pTemp=lHead;
	fp=fopen("library_list.txt","w");
	fprintf(fp,"%d\n",count);
	if(fp==NULL){
		printf("���ܴ򿪸��ļ�! ��������˳�!\n");
		getch();
		exit(1);
	}
    while(pTemp!=NULL){
		fprintf(fp,"%ld %s %s %d %s %d-%d-%d %f\n",pTemp->booknum,pTemp->bookname,pTemp->author,
		                                  pTemp->speciesnumber,pTemp->publishers,
		                                  pTemp->publish_time.year,pTemp->publish_time.month,
										  pTemp->publish_time.day,pTemp->price);
		pTemp=pTemp->next;
	}
	fclose(fp);
	printf("\tͼ����Ϣ����ɹ�!\n\n");
	printf("\t**********�����������...\n");
	getch();
}

