## Python列表

#### 列表的定义

​	name = ['jack','rose']

​	这样就组成了一个列表。

#### 列表的访问

​	通过索引访问，索引从0开始。

​	可以通过索引的[-1]访问列表的最后一个元素。

#### 修改列表的元素

​	直接将我们要修改的元素通过索引找出来，直接赋值就可以覆盖之前的值。

​	例如：

​		name = ['jack','rose','hark']

​		name[0] = 'peak'

​		结果：['peak','rose','hark']

​		这样就可以修改列表中的元素了。

#### 给列表添加元素

---

##### append()

​		给列表尾添加元素。

​		name = ['jack','rose','hark']

​		name.append('peak')

​		print(name)

​		结果：['jack','rose','hark','peak']

---

##### insert()

​		给列表任何位置添加新的元素。

​		name = ['jack','rose','hark']

​		name.insert(0,'peak')

​		print(name)

​		结果：['peak','jack','rose','hark']

​		这样时就是给某个位置添加一个元素，然后将后面的元素后移，也就是将他们的索引全部+1。

#### 从列表中删除元素

---

##### del

​		删除已知位置的元素。

​		name = ['jack','rose','hark']

​		del name[0]

​		print(name)

​		结果：['rose','hark']	

​		删除之后将无法访问被删除的元素。

---

##### pop()

​		删除元素，然后使用被删除元素的值。

​		name = ['jack','rose','hark']

​		name.pop()

​		print(name)

​		结果：['jack','rose']

​		当pop的索引，也就是它括号中没有具体的值时就是将列表的最后一个元素删除。

​		也可以通过索引删除已知位置的元素。

---

##### remove()

​		不知道所要删除元素的索引，但是知到所要删除元素的值。

​		name = ['jack','rose','hark']

​		name.remove('jack')

​		print(name)

​		结果：['rose','hark']		

​		通过remove删除元素之前要判断元素是否还存在于列表中。（通过循环）

#### 组织列表（也就给列表按照一定的规则排序）

---

##### sort()

​		对列表进行永久性排序（按字母顺序），这个排序不可逆转。

​		name = ['jack','rose','hark']

​		name.sort()

​		print(name)

​		结果：['jack','hark','rose']

​		通过把reverse = True当成参数传递给sort()，就可以将元素按照语字母顺序相反的顺序来排列。这也是对列表进行永久性排序。

​		name = ['jack','rose','hark']		

​		name.sort(reverse = True)

​		结果：['rose','hark','jack']

---

##### sorted()

​		对列表进行临时排序（按照字母顺序），并不影响原列表中的元素。

​		name = ['jack','rose','hark']	

​		print(name.sorted())

​		结果：['jack','hark','rose']				

​		也可以通过传递参数（reverse = True）将元素按照字母反序排列，并且不影响原来的次序。

​		name = ['jack','rose','hark']	

​		print(sorted(name,reverse = True))

​		结果：['rose','hark','jack']

​		sorted与sort最大的不同就是不改变原来列表里本来的次序。

---

##### reserve()

​		倒着打印列表（将原来的列表反向后存储）

​		name = ['jack','rose','hark']	

​		print(name)

​		结果：['hark','rose','jack']

---

len()

​		确定列表的长度

​		name = ['jack','rose','hark']	

​		print(len(name))

​		结果：3

​		

