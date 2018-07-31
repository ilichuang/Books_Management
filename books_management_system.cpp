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

/* 主函数 */
int main()
{    
    printscreen0();
	return 0;
}
/* 主界面 */
void printscreen0()
{
	char choice='1';
	while(choice!='0'){
	    system("cls");
	    printf("\t********************************************\n\n");
		printf("\t            欢迎进入图书管理系统\n\n");
	    printf("\t       ====     1.  管理图书     ====\n\n");
		printf("\t       ====     2.  读取文件     ====\n\n");
		printf("\t       ====     3.  保存文件     ====\n\n");
	    printf("\t       ====     0.    退出       ====\n\n");
	    printf("\t********************************************\n\n");
        printf("\t         (请用数字选择要进行的操作!)\n");
    	if( (choice=getche()) != '0' )
	    switch(choice){
            case '1':    printscreen1();    break;
	        case '2':    readfile();    break;
			case '3':    savefile();    break;
	        default:     break;
		}
	}
}
/* 图书信息管理界面 */
void printscreen1()   
{
	char choice='1';
	while(choice!='0'){
	   system("cls");
	    printf("\t********************************************\n\n");
	    printf("\t          欢迎进入图书信息管理系统\n\n");
        printf("\t      ====     1.  查看图书       ====\n\n");
        printf("\t      ====     2.    搜索         ====\n\n");
        printf("\t      ====     3.添加图书信息     ====\n\n");
		printf("\t      ====     4.修改图书信息     ====\n\n");
	    printf("\t      ====     5.删除图书信息     ====\n\n");
        printf("\t      ====     6.录入图书信息     ====\n\n");
	    printf("\t      ====     0.    退出         ====\n\n");
     	printf("\t*******************************************\n\n");
        printf("\t         (请用数字选择要进行的操作!)\n");
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
/* 查看图书 */
void outputbooks()
{
     Booklist pTemp;
	 pTemp=lHead;
	 system("cls");
	 printf("\t************共有%d本书************\n\n",count);
	 int index=1;
	 while(pTemp!=NULL){
		printf("\t------------第%d本书-----------\n\n",index);
        printf("\t图书号:  %08ld",pTemp->booknum);
	    printf("\n\t图书名:  %s",pTemp->bookname);
	    printf("\n\t作者:  %s",pTemp->author);
	    printf("\n\t图书类别号码:  %03d",pTemp->speciesnumber);
	    printf("\n\t出版社:  %s",pTemp->publishers);
	    printf("\n\t出版时间:  ");
	    printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                 pTemp->publish_time.month,
			    		 pTemp->publish_time.day);
        printf("\n\t价格:  %.2f",pTemp->price);
        printf("\n\n\t-------------------------------\n\n");
		pTemp=pTemp->next;
		index++;
	 }
	 printf("按任意键继续!\n"); 
	 getch();
}
/* 搜索 */
void searchbook()
{
	while(1){
	    system("cls");
	    printf("\t\t请选择搜索方式:\n\n");
	    printf("\t\t  *********  1-图书号\n\n"); 
	    printf("\t\t  *********  2-图书名\n\n"); 
	    printf("\t\t  *********  3-作者\n\n"); 
	    printf("\t\t  *********  4-出版社\n\n"); 
	    printf("\t\t  *********  5-图书类型号\n\n");
	    printf("\t\t  *********  0-退出\n\n");
	    printf("\t\t  ----------------请选择:");
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
/* 按图书号搜索 */
void searchbook_num()
{
	int book_num;
	int index=0;
	printf("\n\t\t*********请输入图书号:");
	scanf("%d",&book_num);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(pTemp->booknum==book_num){
			printf("\n\t\t******************\n\n");
			printf("\t\t图书号:  %08ld",pTemp->booknum);
	        printf("\n\t\t图书名:  %s",pTemp->bookname);
	        printf("\n\t\t作者:  %s",pTemp->author);
	        printf("\n\t\t图书类别号码:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t出版社:  %s",pTemp->publishers);
	        printf("\n\t\t出版时间:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t价格:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  未找到图书!");
	printf("\t\t-----  按任意键继续...");
    getch();
}
/* 按图书名搜索 */
void searchbook_name()
{
	char book_name[20];
	int index=0;
	printf("\n\t\t*********请输入图书名:");
	fflush(stdin);
	gets(book_name);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(strcmp(book_name,pTemp->bookname)==0){
			printf("\n\t\t******************\n\n");
			printf("\t\t图书号:  %08ld",pTemp->booknum);
	        printf("\n\t\t图书名:  %s",pTemp->bookname);
	        printf("\n\t\t作者:  %s",pTemp->author);
	        printf("\n\t\t图书类别号码:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t出版社:  %s",pTemp->publishers);
	        printf("\n\t\t出版时间:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t价格:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  未找到图书!");
	printf("\t\t-----  按任意键继续...");
	getch();
}
/* 按作者搜索 */
void searchbook_author()
{
	char book_author[20];
	int index=0;
	printf("\n\t\t*********请输入作者:");
	fflush(stdin);
	gets(book_author);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(strcmp(book_author,pTemp->author)==0){
			printf("\n\t\t******************\n\n");
			printf("\t\t图书号:  %08ld",pTemp->booknum);
	        printf("\n\t\t图书名:  %s",pTemp->bookname);
	        printf("\n\t\t作者:  %s",pTemp->author);
	        printf("\n\t\t图书类别号码:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t出版社:  %s",pTemp->publishers);
	        printf("\n\t\t出版时间:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t价格:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  未找到图书!");
	printf("\t\t-----  按任意键继续...");
    getch();
}
/* 按图书类型号搜索 */
void searchbook_speciesnumber()
{
	int book_speciesnumber;
	int index=0;
	printf("\n\t\t*********请输入图书类型号:");
	scanf("%d",&book_speciesnumber);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(pTemp->speciesnumber==book_speciesnumber){
			printf("\n\t\t******************\n\n");
			printf("\t\t图书号:  %08ld",pTemp->booknum);
	        printf("\n\t\t图书名:  %s",pTemp->bookname);
	        printf("\n\t\t作者:  %s",pTemp->author);
	        printf("\n\t\t图书类别号码:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t出版社:  %s",pTemp->publishers);
	        printf("\n\t\t出版时间:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t价格:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  未找到图书!");
	printf("\t\t-----  按任意键继续...");
    getch();
}
/* 按出版社搜索 */
void searchbook_publisher()
{
	char book_publisher[30];
	int index=0;
	printf("\n\t\t*********请输入出版社:");
	fflush(stdin);
	gets(book_publisher);
	Booklist pTemp;
	pTemp=lHead;
	int flag=1;
	while(index<count){
		if(strcmp(book_publisher,pTemp->publishers)==0){
			printf("\n\t\t******************\n\n");
			printf("\t\t图书号:  %08ld",pTemp->booknum);
	        printf("\n\t\t图书名:  %s",pTemp->bookname);
	        printf("\n\t\t作者:  %s",pTemp->author);
	        printf("\n\t\t图书类别号码:  %03d",pTemp->speciesnumber);
	        printf("\n\t\t出版社:  %s",pTemp->publishers);
	        printf("\n\t\t出版时间:  ");
	        printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
            printf("\n\t\t价格:  %.2f",pTemp->price);
            printf("\n\n\t\t-------------------------------\n\n");
            flag=0;
		}   
		pTemp=pTemp->next;
		index++; 
	}
	if(flag)	printf("\n\t\t**********  未找到图书!");
	printf("\t\t-----  按任意键继续...");
    getch();
}
/* 添加图书信息 */
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
	    printf("\n\t------------第%d本书-----------\n\n",count+1);
        printf("\t图书号:  ");
	    scanf("%ld",&pTemp->booknum);
		fflush(stdin);
	    printf("\n\t图书名:  ");
	    gets(pTemp->bookname);
	    printf("\n\t作者:  ");
	    gets(pTemp->author);
	    printf("\n\t图书类别号码:  ");
	    scanf("%d",&pTemp->speciesnumber);
		fflush(stdin);
	    printf("\n\t出版社:  ");
	    gets(pTemp->publishers);
	    printf("\n\t出版时间:  ");
	    scanf("%d-%d-%d",&pTemp->publish_time.year,
		                 &pTemp->publish_time.month,
			    		 &pTemp->publish_time.day);
        printf("\n\t价格:  ");
	    scanf("%f",&pTemp->price);
        printf("\n\n\t-------------------------------\n\n");
        pTemp->next=NULL;
	    pPre->next=pTemp;
	    pPre=pTemp;
	    count++;
	    printf("\t是否继续添加(Y/N):");
			ch=getche();
	}
}
/* 修改图书信息 */
void changebook()
{
	Booklist pTemp;
	pTemp=lHead;
	system("cls");
	printf("\n\t\t*********  修改操作\n");
	int book_num;
	printf("\n\t\t-----请输入图书号:");
	scanf("%d",&book_num);
	while(pTemp->booknum!=book_num){
		if(pTemp->next==NULL){
		    printf("\n\t\t-----  未找到图书!按任意键退出...\n");
		    getch();
		    return;
    	}      
    	pTemp=pTemp->next;
	}
	printf("\n\t\t******************\n\n");
	printf("\t\t图书号:  %08ld",pTemp->booknum);
    printf("\n\t\t图书名:  %s",pTemp->bookname);
    printf("\n\t\t作者:  %s",pTemp->author);
	printf("\n\t\t图书类别号码:  %03d",pTemp->speciesnumber);
	printf("\n\t\t出版社:  %s",pTemp->publishers);
	printf("\n\t\t出版时间:  ");
	printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
    printf("\n\t\t价格:  %.2f",pTemp->price);
    printf("\n\n\t\t-------------------------------\n\n");
    printf("\t\t  *********  1-图书号\n\n"); 
	printf("\t\t  *********  2-图书名\n\n"); 
    printf("\t\t  *********  3-作者\n\n"); 
	printf("\t\t  *********  4-出版社\n\n"); 
	printf("\t\t  *********  5-图书类型号\n\n");
	printf("\t\t  *********  6-出版时间\n\n");
	printf("\t\t  *********  7-价格\n\n");
	printf("\t\t  *********  0-退出\n\n");
	while(1){
	    printf("\t\t  ----------------请选择要修改的项目:");
	    int choice;
        scanf("%d",&choice);
        switch(choice){
    	    case 1:  printf("\t\t图书号:  ");
		             scanf("%d",&pTemp->booknum);    break;
    	    case 2:  printf("\t\t图书名:  "); 
		             fflush(stdin);  gets(pTemp->bookname);    break;
    	    case 3:  printf("\t\t作者:  ");
		             fflush(stdin);  gets(pTemp->author);    break;
    	    case 4:  printf("\t\t图书类别号码:  ");
		             scanf("%d",&pTemp->speciesnumber);    break;
	        case 5:  printf("\t\t出版社:  ");
		             fflush(stdin);  gets(pTemp->publishers);    break;
		    case 6:  printf("\t\t出版时间:  ");
		             scanf("%d-%d-%d",&pTemp->publish_time.year,
					                  &pTemp->publish_time.month, 
									  &pTemp->publish_time.day);    break;
		    case 7:  printf("\t\t价格:  ");
		             scanf("%f",&pTemp->price);    break;
		    case 0:  return;
	        default:    break;
	    }
	}
	printf("\n\n\t\t修改完成!按任意键退出...\n");
	getch();
} 
/* 删除图书信息 */
void deletebook()
{
	system("cls");
	int number;
	printf("\n\n\t\t*********删除操作\n");
	printf("\n\t\t图书号：");
	scanf("%d",&number); 
	Booklist pTemp,pPre;
	pTemp=lHead;
	pPre=pTemp;
	while(pTemp->booknum!=number){
		pPre=pTemp;
		pTemp=pTemp->next;
	}
	printf("\n\t\t******************\n\n");
	printf("\t\t图书号:  %08ld",pTemp->booknum);
    printf("\n\t\t图书名:  %s",pTemp->bookname);
    printf("\n\t\t作者:  %s",pTemp->author);
	printf("\n\t\t图书类别号码:  %03d",pTemp->speciesnumber);
	printf("\n\t\t出版社:  %s",pTemp->publishers);
	printf("\n\t\t出版时间:  ");
	printf("%04d-%02d-%02d",pTemp->publish_time.year,
		                     pTemp->publish_time.month,
			    	    	 pTemp->publish_time.day);
    printf("\n\t\t价格:  %.2f",pTemp->price);
    printf("\n\n\t\t-------------------------------\n\n");
	printf("\t\t*********  确认删除?\n\n");
	printf("\n\t\t  *****  1-确认\n");
	printf("\n\t\t  *****  2-取消\n");
	int choice;
	scanf("%d",&choice);
	if(choice==2)    return;
	if(pTemp->booknum==lHead->booknum)   lHead=lHead->next;
	pPre->next=pTemp->next;
	free(pTemp);
	count--;
	printf("\t\t---------  删除成功!按任意键继续...\n");
	getch();
}
/* 图书信息录入 */
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
	    printf("\n\t------------第%d本书-----------\n\n",count);
        printf("\t图书号:  ");
	    scanf("%ld",&pNew->booknum);
		fflush(stdin);
	    printf("\n\t图书名:  ");
	    gets(pNew->bookname);
	    printf("\n\t作者:  ");
	    gets(pNew->author);
	    printf("\n\t图书类别号码:  ");
	    scanf("%d",&pNew->speciesnumber);
		fflush(stdin);
	    printf("\n\t出版社:  ");
	    gets(pNew->publishers);
	    printf("\n\t出版时间:  ");
	    scanf("%d-%d-%d",&pNew->publish_time.year,
		                 &pNew->publish_time.month,
			    		 &pNew->publish_time.day);
        printf("\n\t价格:  ");
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
		printf("\t是否继续录入(Y/N):");
		//do{
			ch=getche();
		//}while(toupper(ch)!=('Y'||'N'));
	}    
	return pHead;
}
/* 图书信息读取 */
void readfile()
{
	FILE *fp;
	fp=fopen("library_list.txt","r");
	if(fp==NULL){
		printf("\n\n\t*******库存文件不存在!请创建!\n");
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
	printf("\t读取图书信息成功!\n\n");
	printf("\t*************按任意键继续...\n");
	getch();
}
/* 图书信息保存 */
void savefile()
{
	int choice;
	printf("\n\t\t请确认是否保存?\n");
	printf("\n\t\t  *****  1-确认\n");
	printf("\n\t\t  *****  2-取消\n");
	scanf("%d",&choice);
	if(choice==2)    return;
	FILE *fp;
	Booklist pTemp;
    pTemp=lHead;
	fp=fopen("library_list.txt","w");
	fprintf(fp,"%d\n",count);
	if(fp==NULL){
		printf("不能打开该文件! 按任意键退出!\n");
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
	printf("\t图书信息保存成功!\n\n");
	printf("\t**********按任意键继续...\n");
	getch();
}

