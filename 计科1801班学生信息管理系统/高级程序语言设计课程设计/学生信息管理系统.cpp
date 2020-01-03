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
	printf("������ѧ����Ϣ:\nѧ�ţ�");
	scanf("%s",&p1->num);
	printf("������");
	scanf("%s",&p1->name);
	printf("���䣺");
	scanf("%s",&p1->age );
	printf("�Ա�");
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
		printf("ѧ��\t\t����\t����\t�Ա�\n");
		do
		{
			printf("%-16s%-8s%-8s%-16s\n",p->num,p->name,p->age,p->sex);
			p=p->next;                           
		}while(p!=NULL);
	}
	else
		printf("��δ¼�����ݣ�����\n");
	system("pause");
	system("cls");
}

void Delete()
{
	if(n!=0)
	{
		struct student *f,*l;                              
		char a[20];
		printf("������Ҫɾ��ѧ����ѧ�ţ�");
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
		printf("��δ¼�����ݣ�����\n");
    printf("�����Ѿ���ɾ��\n");
	system("pause");                                    
	system("cls");
}
void change()
{
	if(n!=0)
	{
		int c;
		char a[20];
		printf("������Ҫ�޸�ѧ����ѧ�ţ�");
		scanf("%s",&a);
		p=head;
		do
		{
			if(strcmp(a,p->num )==0)
			{
				printf("\n���޸�����Ϣ���£�\nѧ��\t\t����\t����\t�Ա�\n");
				printf("%-16s%-8s%-8s%-16s\n",p->num,p->name,p->age,p->sex );
				break;
			}
			p=p->next;                            
		}while(p!=NULL);
		printf("\n\n1.�޸�ѧ��\n2.�޸�����\n3.�޸�����\n4.�޸��Ա�\n5.�˳��޸�\n\n");
		scanf("%d",&c);
		switch(c)
		{
		case 1:
			printf("ѧ���޸�Ϊ��");
			scanf("%s",&p->num);break;
		case 2:
			printf("�����޸�Ϊ��");
			scanf("%s",&p->name);break;
		case 3:
			printf("�����޸�Ϊ��");
			scanf("%s",&p->age);break;
		case 4:
			printf("�Ա��޸�Ϊ��");
			scanf("%s",&p->sex );break;
		case 5:
			break;
		}
		printf("\n\n�����ɹ�!\n\n");
	}
	else
		printf("��δ¼�����ݣ�����\n");
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
			printf("д�����ݳ���\n");  
			fclose(fp);
			break;
        }  
        p=p->next;  
    }  
    fclose(fp);  
	printf("�洢���\n");
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
	printf("��ȡ���!\n\n");
	system("pause");
	system("cls");
}
void find ()
{
	if(n!=0) 
	{
	char a[20];
	printf("������Ҫ���ҵ�ѧ�ţ�");
	scanf("%s",&a);
	p=head;
	do
	{
		if(strcmp(a,p->num )==0)
		{
			printf("\n��Ϣ�ѱ��ҵ���\nѧ��\t\t����\t����\t�Ա�\n");
			printf("%-8s%-16s%-8s%-16s\n\n",p->num,p->name,p->age,p->sex );
		}
		p=p->next;                           
	}while(p!=NULL);
	system("pause");
	system("cls");
   }
   else 
      	{printf("��δ¼�����ݣ�����\n");system("pause");}
}
 main()                                 
{
	int a=1;
	while(a!=0)
	{
		system("cls");
	    printf ("---------------------------------\n");
        printf ("       ѧ �� �� Ϣ �� ��         \n");
        printf ("        1.�½�ѧ����Ϣ           \n");
        printf ("        2.��ѯѧ����Ϣ           \n");
        printf ("        3.�޸�ѧ����Ϣ           \n");
        printf ("        4.ɾ��ѧ����Ϣ           \n");
        printf ("        5.��ʾȫ����Ϣ           \n");
        printf ("        6.�����ļ�               \n");
        printf ("        7.��ȡ�ļ�               \n");
        printf ("        0.�رմ���               \n");
        printf ("---------------------------------\n");
        printf ("������ѡ����Ŀ��");
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
			printf("�����������󣡣���\n");
			system("pause");
		}
	}
}


