  #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Length sizeof(struct student)      
int n=0;
struct student 
{
	char num[20]; 
	char name[20];                             
    char age[5];
	char sex[10];                              
	struct student *next;   
}*head,*p,*p1,*p2;      
void add()              
{
	p1=(struct student *)malloc(Length);         
	if(n==0)                                     
		head=p1;                                
	else p2->next=p1;                           
	system("cls");
	printf("请输入学生信息:\n学号：");
	scanf("%s",&p1->num);
	printf("姓名：");
	scanf("%s",&p1->name);
	printf("年龄：");
	scanf("%s",&p1->age );
	printf("性别：");
	scanf("%s",&p1->sex );
	p2=p1;                                      
	p2->next=NULL;                              
	n+=1;                                      
	system("pause");
	system("cls");
}
void print()
{
	if(n!=0)
	{
		p=head;                                   
		system("cls");
		printf("学号\t\t姓名\t年龄\t性别\n");
		do
		{
			printf("%-16s%-8s%-8s%-16s\n",p->num,p->name,p->age,p->sex);
			p=p->next;                           
		}while(p!=NULL);
	}
	else
		printf("还未录入数据！！！\n");
	system("pause");
	system("cls");
}

void Delete()
{
	if(n!=0)
	{
		struct student *f,*l;                              
		char a[20];
		printf("请输入要删除学生的学号：");
		scanf("%s",&a);
		p=head;
		if(strcmp(head->num ,a)==0)
		{f=head;head=head->next;free(f);}
		else
		{
			do
			{
				if(strcmp(p->num ,a)==0)
				{f=p;l->next=p->next;free(f);break;}
				l=p;                                        
				p=p->next;
			}while(p!=NULL);
		}
	}
	else
		printf("还未录入数据！！！\n");
    printf("数据已经被删除\n");
	system("pause");                                    
	system("cls");
}
void change()
{
	if(n!=0)
	{
		int c;
		char a[20];
		printf("请输入要修改学生的学号：");
		scanf("%s",&a);
		p=head;
		do
		{
			if(strcmp(a,p->num )==0)
			{
				printf("\n被修改人信息如下：\n学号\t\t姓名\t年龄\t性别\n");
				printf("%-16s%-8s%-8s%-16s\n",p->num,p->name,p->age,p->sex );
				break;
			}
			p=p->next;                            
		}while(p!=NULL);
		printf("\n\n1.修改学号\n2.修改姓名\n3.修改年龄\n4.修改性别\n5.退出修改\n\n");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			printf("学号修改为：");
			scanf("%s",&p->num);break;
		case 2:
			printf("姓名修改为：");
			scanf("%s",&p->name);break;
		case 3:
			printf("年龄修改为：");
			scanf("%s",&p->age);break;
		case 4:
			printf("性别修改为：");
			scanf("%s",&p->sex );break;
		case 5:
			break;
		}
		printf("\n\n操作成功!\n\n");
	}
	else
		printf("还未录入数据！！！\n");
	system("pause");
	system("cls");
}
void save()
{
    FILE *fp;  
    struct student *p;  
    if((fp=fopen("stu.txt","wb"))==NULL)
		printf("Can not open the file!");  
    p=head;  
    while(p!=NULL)
	{  
		if(fwrite(p,Length,1,fp)!=1)
		{
			printf("写入数据出错\n");  
			fclose(fp);
			break;
        }  
        p=p->next;  
    }  
    fclose(fp);  
	printf("存储完成\n");
	system("pause");
	system("cls");
}
void read()
{
	FILE *fp;
	if((fp=fopen("stu.txt","rb+"))==NULL)
	{printf("Can not open file!");exit(0);}
    do
	{ 
		p1=(struct student *)malloc(Length);
		if(n==0)                                    
			head=p1;                                 
		else   
			p2->next=p1;
		fread(p1,Length,1,fp);
		p2=p1;
		n+=1;
    }while(p2->next!=NULL);
    fclose(fp);
	printf("读取完成!\n\n");
	system("pause");
	system("cls");
}
void find ()
{
	if(n!=0) 
	{
	char a[20];
	printf("请输入要查找的学号：");
	scanf("%s",&a);
	p=head;
	do
	{
		if(strcmp(a,p->num )==0)
		{
			printf("\n信息已被找到：\n学号\t\t姓名\t年龄\t性别\n");
			printf("%-8s%-16s%-8s%-16s\n\n",p->num,p->name,p->age,p->sex );
		}
		p=p->next;                           
	}while(p!=NULL);
	system("pause");
	system("cls");
   }
   else 
      	{printf("还未录入数据！！！\n");system("pause");}
}
 main()                                 
{
	int a=1;
	while(a!=0)
	{
		system("cls");
	    printf ("---------------------------------\n");
        printf ("       学 生 信 息 管 理         \n");
        printf ("        1.新建学生信息           \n");
        printf ("        2.查询学生信息           \n");
        printf ("        3.修改学生信息           \n");
        printf ("        4.删除学生信息           \n");
        printf ("        5.显示全部信息           \n");
        printf ("        6.保存文件               \n");
        printf ("        7.读取文件               \n");
        printf ("        0.关闭窗口               \n");
        printf ("---------------------------------\n");
        printf ("请输入选择项目：");
		scanf("%d",&a);
		if(a>=0&&a<=9)
		{
			switch(a)
			{
			case 1:
				add();
				break;
			case 2:
				find();
				break;
			case 3:
				change();
				break;
			case 4:
				Delete();
				break;
     		case 5:
     			print();
				break;
			case 6:
				save();
				break;
			case 7:
				read();
				break;
 
			}
		}
		else
		{
			printf("输入数据有误！！！\n");
			system("pause");
		}
	}
}


