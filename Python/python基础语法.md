## python基础语法

 
##### 变量
    
    message = "Hello Python world!"
    print(message)
    -----
    Hello Python world!
    这是一个变量使用的实例。
    
    我理解的变量有一下几个特点：
        1）.变量就像当与一个容器，在容器里面保存内容。
        2）.变量在命名时要遵守几个规则：只能由字母、数字、下划线组成。且数字不能为开头。
        3）.不能使用python的关键字或者函数名做变量名。
##### 字符串

    字符串的的引号可以是双引号或者单引号。但是在使用时要注意语法，避免出现同种使用的错误。
    例如：
        message = "He's mother!"
        message = 'He's mother!'
        就像这样，第二个就会报错。
        
    title()
        将文本以首字母大写的方式显示。
        例如：
            message = "ada lovelace"
            print(message.title())
            -----
            Ada Lovelace
    
    upper()
        将文本全部大写处理
        例如：
            message = "Ada Lovelace"
            print(message.upper())
            -----
            ADA LOVELACE
    
    lower()
        将文本全部小写处理
        例如：
            message = "Ada Lovelace"
            print(message.lower())
            -----
            ada lovelace
            
    合并字符串
        name_1 = "ada"
        name-2 = "lovelace"
        name = name_1 + " " +name_2
        print(name.title())
        -----
        Ada Lovelace
        
    删除空白
        strip
            删除左右两边的空白。
        lstrip
            删除左边的空白
        rstrip
            删除右边的空白
        例如：
            name = "python "
            name_1 = " response"
            print(name.rstrip() + name_1.lstrip())
            name_2 = " python "
            print(name_2.strip())
            
##### print()
   
    输出所需的内容。
    print('')
    print("")
    括号中的 ""、''是相同的，python中对引号的使用没有区分。
   
##### 数字

    加减乘除
    
    除（/），这是真正的除，3 / 2 = 1.5     （这是在python3中）
    python2中
    3 / 2 = 1
    3.0/2 = 1.5
    3/2.0 = 1.5
    3.0/2.0=1.5
    （这是在python2中）
    
    浮点数：
        >>>1*0.2
        0.2
        >>>0.2+0.1
        0.300000000004
        这儿结果包含的小数位可能是不确定的。
        
    str()
        在打印数字的时候加上str避免出错。
        
##### 注释（#）
    在我们的以后所有的程序中必须有注释。这可以增加我们程序的可读性。