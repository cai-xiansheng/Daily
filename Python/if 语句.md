## if 语句

#### 检查特定值是否在列表中

​	name == 'alix'

​	names = ['alix','admin','user']

​	if **name in names**:

​		print('"alix"在列表中！')

​	else：

​		print('没找到！')

#### 检查特定值不在列表中

​	上面的if语句变为**name not in names:**

​	经过这样的处理就可以检验特定值不在列表中。 

#### 布尔值表达式

​	布尔表达式（条件测试的别名）的值要么是**True**，要么就是**False**

#### *if - else*语句

​	**if** name in names**:**

​		print('"alix"在列表中！')

​	**else：**

​		print('没找到！')		

#### *if - elif - else*语句

​	**if** 条件1**:**

​		print('条件1')

​	**elif** 条件2**:**

​		print('条件2')

​	**else：**

​		print('没找到！')		

​	*不仅这样，还可以使用多个elif代码块.*

​	else 代码块也可以省略。

#### 确定列表不是空的

​	name = []

​	if name:

​		print ('列表不是空的！')

​	else:

​		print('列表是空的！')

## 代码风格

​	python的代码风格[PEP8](https://www.jianshu.com/p/ffcc66bab3ce).