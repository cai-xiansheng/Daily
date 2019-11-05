## 	javascript
1.javascript的一些特性

	javascript代码必须位于<script>与</script>之间
	javascript是HTML默认的脚本语言可以不使用type属性，如：<script type="text/javascript">
	js可以被放置在<head>和<body>中
2.javascript显示
	
	innerHTML：写入HTML元素
		例：document.getementById("id").innerHTML=5+6;
		上例中id属性定义HTML元素，属性定义HTML内容
	document.write()
	window.alert():使用警告框来显示数据
	console.log()通过控制台来显示数据
3.js语法
	
	var:声明变量，声明可跨多行，
	值的运算，值可以是多种类型的
	注释：//或/* */	
	javascript不能使用连字符，连字符预留给减法，使用驼峰式大小写
	把要给数值放入引号中，其余数值会被视作字符串并被级联。
		例：
			var x = "8" + 3 + 5;		结果：835
			var x = 3 + 5 + "8";		结果：88
4.js算术运算符
	
	**：幂		等同于var z = Math.pow(5,2);   //结果是 25
		例：var z = 5 ** 2;          // 结果是 25
5.js数据类型
	
	js变量能保存多种数据类型：数值、数组、对象等。
		例：var length = 7;                             // 数字
			var lastName = "Gates";                      // 字符串
			var cars = ["Porsche", "Volvo", "BMW"];         // 数组
			var x = {firstName:"Bill", lastName:"Gates"};    
			// 对象 
			
	数值与字符串相加时，js把数值当作字符串
		
		例：var x = "911" + "Porsche";
	
	js从左向右运算表达式时，不同的次序会产生不同的结果
		
		例：var x = 911 + 7 + "Porsche";
				结果：918Porsche		//把911与7当作数值，最后才遇见"Porsche"
			var x = "Porsche" + 911 + 7;
				结果：Porsche9117		//把"Porsche"当作字符串，所以全部按照字符串处理。
	js动态类型
		
		相同变量可用作不同的类型，我的理解：可以互相覆盖，之
		前所接触的知识里面只是同类型的覆盖。
	
	js字符串值
		
		两层不同的结构用不同的引号。只要隔层不重复就ok.
	
	js数组
		
		数组用方括号书写，数组的项目用逗号隔开。
			例：var cars = ["Porsche","Volvo","BWM"];
			
	js对象
	
		对象用花括号书写，由逗号隔开;属性即name:value
			例：var person = {firstName:"Bill"，lastName:"Gates",age:62,eyecolor:"blue"};
			
	typeof运算符
		typeof 返回值都有string、number、boolean、undefined
		typeof 运算符返回变量或者表达式的类型
			例：typeof "bill Gates"		//返回"string"
				typeof (7+8)		//返回"number"
		typeof 运算符返回可以有以下两种类型
			object ：typeof 运算符把对象、数组、NULL返回 object
			functon: typeof 运算符不会把函数返回为object,返回为function
	undefined   任何变量可以通过undefined设置值来进行清空			
6.js函数

	函数通过function定义,后面加函数名与括号
		例：function myFunction(p1,p2){
								return p1*p2;
								}
	函数调用
		事件发生时、代码调用时、自调用；这四种调用方式。
		使用()运算符调用函数，toCelsius引用的是函数对象，而toCelsius引用的是函数结果。
		
7.js对象

	对象也是变量，可以包括很多值
	书写有规范	名称：值（属性）
		例：var person = {firstName:"Bill", lastName:"Gates", age:62, eyeColor:"blue"};
	对象也可以有方法，方法是在对象上执行对的动作。
		例：var person = {
			  firstName: "Bill",
			  lastName : "Gates",
			  id       : 678,
			  fullName : function() {
				return this.firstName + " " + this.lastName;
			  }
			};
	对象定义：折行和空格都是被允许的。
	对象的属性的访问：perso.lastName;	通过点写链接
					或者person["lastName"];		通过括号来书写。
	this关键词：//难点，后面会提到
		this 引用函数的“拥有者”，也就是指对象
		
8.js事件（涉及到DOM）

	javascript事件应对HTML的动作。
	通过this改变自身内容：this.innerHTML
		例：<button onclick = "this.innerHTML = Date()">现在时间是？</button>
	通过函数调用：
		例：<script>
			function displayDate() {
				document.getElementById("demo").innerHTML = Date();
			}
			</script>		//定义函数
			<button onclick="displayDate()">时间是？</button>	//调用函数
			
9.js字符串

	字符串中使用引号，只要不匹配围绕字符串的引号即可。
	
	length:可以测字符串的长度
	
		例： var txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			 var sln = txt.length;    结果为：26
	特殊字符
	
		\:转义字符
			var x = "中国是瓷器的故乡，因此 china 与\"China（中国）\"同名。"	
			结果：中国是瓷器的故乡，因此 china 与"China（中国）"同名。
		\：此符号后面可以加空格，某些浏览器是不允许输入空格的，所以通过此方法可以输入空格。
	字符串可以通过new定义为对象，
	
		例：var firstName = new String("Bill")
	对象无法比较！！！
	
	indexOf:查找字符串中指定文本首次出现的索引（位置）					//可以设置第一次开始检索的位置
	
	lastIndexOf:此方法返回指定文本在字符串中最后一次出现的索引		//最后一次，也可以设置第一次检索的位置
		例：var str = "The full name of China is the People's Republic of China.";
            var pos = str.lastIndexOf("China");
		另外一种使用方法： var pos = str.lastIndexOf("China",50);	//假设参数是50，则从位置50开始向前检索，直到字符串的起点。
		
	search():也可以检索	
	
		例：var pos = str .search("China");		//返回匹配的位置
		
	提取字符串：
	
		slice(start,end)	//终止与索引位置，可以接受负索引，省略第二个参数则剪切字符串的剩余部分。
		substring(start,end)	//不能接受负索引
		substr(start,end)	//第二个参数规定被提取部分的长度
		
	replace:替换字符串内容
	
		对大小写敏感，/g对全局所有变量进行替换。
			例：str = "Please visit Microsoft and Microsoft!";
				var n = str.replace(/Microsoft/g, "W3School");
				
	转换大小写：
	    toUpperCase()	toLowerCase()
	    
	连接两个或多个字符串：concatenate（）
	
		var text1 = "hello";
		var text2 = "world";
		var text3 = text1.con(" ",text2);
		
	删除字符两端的空白符：trim()
	属性访问：
	
		例：var str = "HELLO WORLD";
			str[0];                   // 返回 H
