### 循环结构

        
    if()循环
        
        if()循环可以用三目运算符代替。
        
    switch()循环
        
        结构：
            switch(i)
            {
                case 常量 :语句1;break;
                case 常量 :语句2;break;
                default:语句3;
            }
            
    while()循环
        当循环条件为真时，就执行循环体语句。
        
    do···while()循环
        结构：
            do
            {
                语句；
            }while(表达式);
            特点:先无条件执行一次，然后再去判断循环条件。
            
    for()循环
        结构:
            for (int i = 0; i < count; ++i)
        	{
        	    语句;
        	}
    
    continue:提前结束本次循环
    
    break:提前终止循环
    
    控制每行输出的数
        if(i%5==0) printf("\n");
        所要输出的语句
        
    %s:字符串
        printf("%s",c);
        
    递归调用：
        就是一个函数在运行时把自己调用了。
        递归的实例：
        
```
    /*hanoi*/
    #include <stdio.h>
    int main()
    {
    	void hanoi(int n,char one,char two,char three);
    	int m;
    	printf("input the number of diskes:");
    	scanf("%d",&m);
    	printf("The step to move %d diskes:\n",m);
    	hanoi(m,'A','B','C');
    }
    void hanoi(int n,char one,char two,char three)
    {
    	void move(char x,char y);
    	if (n==1)
    		move(one,three);
    	else
    	{
    		hanoi(n-1,one,three,two);
    		move(one,three);
    		hanoi(n-1,two,one,three);
    	}
    }
    void move(char x,char y)
    {
    	printf("%c-->%c\n",x,y);
    }
    
    
    
```
#### 局部变量：

    定义在函数内部的，只在函数的内部起效果。
    
#### 全局变量：
  
    定义在函数的外边，在所有函数中都有效果。

#### 静态存储方式：
  
    程序运行期间由系统分配的固定的存储空间，在整个文件内有效。
    
#### 动态存储方式
  
    在程序运行期间根据需要进行动态的分配空间，在某个函数内有效。
    
#### 内部函数

    只在一个函数内部起作用，不能被其他文件所调用。
    
#### 外部函数(extern)

    可以供其他文件中的调用。
    例：
        extern int fun(int a,int b)
        {
            
        }
        
        
#### 指针：

    定义指针:
        类型名 *指针变量名;
        int *pointer;
    pointer     地址
    *pointer    数据
    &pointer    原内容地址
        
    指针与数组
        定义时：
            int *p=a;
            等效于:int *p=a;p=&a[0];
            这样是将a数组元素(即a[0])的首地址赋给指针变量p(并非赋值*p)
        指针的运算:
            例：p+1     指向同一数组的的下一个元素
                p-1     指向同一数组的的上一个元素
                p++
                p--
                
        通过指针引用数组元素
            1.下表法：
                a[i]
            2.指针法：
                *(a+i)
                *(p+i)
                
#### 结构体(struct):
    
    结构：
        struct 结构体名
        {
            成员表列
        }
        struct 
        {
            成员列表
        }变量名列表
        
#### 结构体数组
        
    1.声明结构体类型
    2.定义一个指向结构体类型数据的指针变量
    例:
        struct student stu[],*p=stu;
        结构体数组          结构体指针
        
#### 链表
    
    struct student 
    {
        成员列表;
        struct student *next;
    }
    
#### 动态链表
    
    在需要时通过 malloc来拓展空间，然后再进行数据的操作。
    在删除数据时通过next删除要删除的元素，然后可以通过free来释放被删除元素所占的空间。
    
#### 用typedof声明新元素的类型
    
    例:
        typedof struct
        {
            int month;
            int day;
            int year;
        }Date;
        
        以上结构声明了一个新类型名Date，代表上面的结构体。所以可以用上面的新的类型名来定义变量。
        例:
            Date birthday;
            Date *p;
            
            
#### 文件的处理
    
    文件类型指针（文件指针）FILE
        FILE结构体类型的信息已经包含在stdio.h文件中
        定义一个指向文件型数据的指针 FILE *fp;  通过文件指针变量能够找到与它相关联的文件。
        
    文件的操作
        
        fopen(文件名，使用方式);打开文件
        使用方式:r,w,a,rb,wb,ab,w+,r+,a+,
        
        
        fclose(文件指针);关闭文件