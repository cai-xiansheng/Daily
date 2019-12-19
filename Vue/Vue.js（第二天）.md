## Vue过滤器

```vue
		<div id="app2">
			<h3>{{dt|dateFormat('')}}</h3>
		</div>	
	<script>
			//全局的过滤器，进行时间的格式化
			//所谓的全局过滤器就是所有VM实例都是共享的
			Vue.filter('dateFormat',function(dateStr,pattern = 'yyyy-mm-dd'){
				//根据给定时间字符串，得到特定的时间
				var dt = new Date(dateStr)
				var y = dt.getFullYear()
				var m = dt.getMonth()
				var d = dt.getDate()
				
				// return y + '-' + m + '-' d
				
				if(pattern.toLowerCase() === 'yyyy-mm-dd'){
					return `${y}-${m}-${d}`
				}else{
					var hh = dt.getHours()
					var mm = dt.getMinutes()
					var ss = dt.getSeconds()
					
					
					return `${y}-${m}-${d} ${hh}:${mm}:${ss}`
				}
			})
			//过滤器的定义语法
			//Vue.filter('过滤器的名称',function(){})
			//过滤器中的function,中的第一个参数已经被固定死了，永远都是过滤器 管道修饰符 传递过来的数据
        
        //*********************************************************************
			//如何定义一个私有的过滤器（局部）
			var vm2 = new Vue({
				el:'#app2',
				data:{
					dt : new Date(),
				},
				methods:{
					
				},
				filters:{
					//定义私有过滤器，过滤器有两个条件，【过滤器名称 和 处理函数】
					//过滤器调用的时候，采用的就是就近原则，如果私有过滤器和全局过滤器名称相同，这时候优先调用私有过滤器
					dateFormat:function(dateStr,pattern){
						var dt = new Date(dateStr)
						var y = dt.getFullYear()
						var m = (dt.getMonth() + 1).toString().padStart(2,'0')
						var d = dt.getDate().toString().padStart(2,'0')
						
						// return y + '-' + m + '-' d
						
						if(pattern.toLowerCase() === 'yyyy-mm-dd'){
							return `${y}-${m}-${d}`
						}else{
							var hh = dt.getHours().toString().padStart(2,'0')
							var mm = dt.getMinutes().toString().padStart(2,'0')
							var ss = dt.getSeconds().toString().padStart(2,'0')
							
							
							return `${y}-${m}-${d} ${hh}:${mm}:${ss}`+'-------'
						}
					}
				}
			})
         </script>
```

+ 全局过滤器
  - 所谓的全局过滤器就是所有VM实例都是共享的
+ 私有的过滤器（局部）
  - 过滤器调用的时候，采用的就是就近原则，如果私有过滤器和全局过滤器名称相同，这时候优先调用私有过滤器

## 自定义全局案件修饰符

> 定义：Vue.config.keyCodes.f2 = 113

> 使用：<input type="text" v-model="name" @keyup.f2="add"/>

## Vue钩子

### 全局指令

```html
<script>
    		//使用vue.directive() 定义全局指令 v-focus
			//其中：参数1 ：指令的名称，注意，在定义的时候，指令的名称前面，不用加v-前缀，
			//但是：在调用的时候，必须在指令名称之前 加上v-前缀来进行强调
			//参数2是一个对象，这个对象身上，有一些钩子函数，这些函数在特定的阶段，可以执行相应的操作
			//使用directive来定义v-指令(全局)。
			Vue.directive('focus',{
				bind:function(el){
					//每当指令绑定到元素上的时候，会立即执行这个bind这个函数，只执行一次
					//注意：在每个函数中，第一个参数永远是el，表示被绑定了指令的那个元素，这个el参数，是一个原生的js对象
					//在元素刚绑定了指令的时候，还没有插入到DOM中去，这时候，调用focus方法没有作用
					//因为，一个元素，只有插入了dom之后，才能获取焦点
					// el.focus
				},
				inserted:function(el){
					//inserted表示元素插入到DOM中的时候，会执行inserted函数
					el.focus()//这个focus()是真正的将焦点聚集到input上的。
					//和js行为有关的操作，最好在inserted中，防止行为不生效
				},
				updated:function(){
					//当VNode更新的时候，会执行updated（DOM节点更新），可能会多次触发
				},
			})
			
			Vue.directive('color',{
				//binding 形参
				bind:function(el,binding){
					//样式只要通过指令绑定给了元素，不管这个元素有没有被插入到页面中去，这个元素肯定有一个内联样式
					//将来元素肯定会显示在页面中，这时候，浏览器的渲染引擎必然会解析样式，应用给这个元素
					// el.style.color = 'red'
					//和样式相关的操作，一般都可以在bind中执行
					/* console.log(binding.name)//color
					console.log(binding.value)//blue
					console.log(binding.expression)//'blue' */
					
					el.style.color = binding.value
				},
				inserted:function(el){
					
				},
				updated:function(el){
					
				}
			})
</script>
```

+ 使用vue.directive() 定义全局指令
+ bind:function(el){}
  + 每当指令绑定到元素上的时候，会立即执行这个bind这个函数，只执行一次
  + 注意：在每个函数中，第一个参数永远是el，表示被绑定了指令的那个元素，这个el参数，是一个原生的js对象
  + 与样式相关的操作，一般都可以在bind中执行
+ inserted:function(el){}
  + inserted表示元素插入到DOM中的时候，会执行inserted函数
  + 和js行为有关的操作，最好在inserted中，防止行为不生效
+ updated:function(){}
  + 当VNode更新的时候，会执行updated（DOM节点更新），可能会多次触发

### 局部指令

```html
<script>
			var vm2 = new Vue({
				el:'#app2',
				data:{
					dt : new Date(),
				},
				methods:{
					//定义操作事件
				},
				filters:{
					//通过filters来定义局部过滤器
				},	
				directives:{
					//自定义私有指令
					//设置字体粗细
					'fontweight':{//这个大括号里的就是一个对象
						bind:function(el,binding){
							el.style.fontweight = binding.value
						}
					},
					'fontsize':function(el,binding){//注意：这个function等同于把代码写到了bind和update中去
						el.style.fontSize = parseInt(binding.value)+'px'
						//el.style.fontSize中的fontSize 并不是我们的指令名称，而是属性名
					}
				}
			})
</script>
```

+ directives:{}
  + 在这个结构中定义私有指令
+ 'fontweight':{}
  + 对属性的操作。

### 指令的简写

+ 'fontsize':function(el,binding){}
  + 注意：这个function等同于把代码写到了bind和update中去

## 生命周期函数

 ```html
	<body>
		<div id="app">
			<input type="button" value="修改msg" @click="msg='no'"/>
			<h3 id="h3">{{msg}}</h3>
		</div>
		
		
		<script type="text/javascript">
			//创建Vue实例，得到ViewModel
			var vm = new Vue({
				el:'#app',
				data:{
					msg:'ok'
				},
				methods:{
					show(){
						console.log('执行了show方法')
					}
				},
				beforeCreate() {
					//这是我们遇到的第一个声明周期函数，表示实例完全被创建出来之前，会执行它
					// console.log(this.msg)
					// this.show()
					//注意：在beforeCreate生命周期函数执行的时候，data和methods中的数据都还没有初始化
				},
				created() {
					//这是遇到的第二个生命周期函数
					// console.log(this.msg)
					// this.show()
					//在create中，data和methods都已经被初始化好了！
					//如果要调用methods中的方法，或者data中的数据，最早在create中操作
				},
				beforeMount() {
					//这是遇到的第三个生命周期函数，表示已经在内存中编辑完成了，但是尚未把模板渲染到页面中去
					console.log(document.getElementById('h3').innerText)//{{msg}}
					//在beforeMount执行的时候，页面中的元素，还没有被真正的替换过来，只是写的一些模板字符串
				},
				mounted() {
					//这是我们遇到的第四个生命周期函数，表示内存中的模板已经真实的挂载到页面中共，用户已经可以看到渲染好的页面了
					console.log(document.getElementById('h3').innerText)//ok
					//注意：mounted是实例创建期间的最后一个生命周期函数，当执行完mounted就表示，实力已经被完全创建好了，此时，如果没有其他操作的话，这个实例，就静静的在内存中不动了。
				},
				
				
				
				//接下来是运行中的两个事件
				beforeUpdate() {
					//这时候，表示我们的界面还没有被更新，【数据肯定被更新了】
					console.log('界面上的元素内容：' + document.getElementById('h3').innerText)//ok
					console.log('data中的msg数据是：' + this.msg)//no
					//得出结论：当执行beforeUpdate的时候，页面中的显示数据，还是旧的，此时data中的数据是最新的，页面中的数据尚未和data数据同步
				},
				updated() {
					console.log('界面上的元素内容：' + document.getElementById('h3').innerText)//no
					console.log('data中的msg数据是：' + this.msg)//no
					//updated 事件执行的时候，页面data数据已经保持同步了，都是最新的
				}
			})	
		</script>
	</body>
 ```

![lifecycle](C:\Users\张辉\Desktop\gits\Daily\Vue\imgs\lifecycle.png)

## vue-resource基本使用

```html
	<head>
		<meta charset="utf-8">
		<title></title>
		<script src="lib/vue.js" type="text/javascript" charset="utf-8"></script>
		<!-- 注意：vue-resource依赖于Vue，所以先后顺序要注意 -->
		<!-- this.$http.jsonp -->
		<script src="https://cdn.bootcss.com/vue-resource/1.3.4/vue-resource.js"></script>
	</head>
	<body>
		<div id="app">
			<input type="button" value="get请求" @click="getInfo"/>
			<input type="button" value="post请求" @click="postInfo"/>
			<input type="button" value="jsonp请求" @click="jsonpInfo"/>
		</div>
		
		
		<script type="text/javascript">
			//创建Vue实例，得到ViewModel
			var vm = new Vue({
				el:'#app',
				data:{
					
				},
				methods:{
					getInfo(){
						//发起get请求
						//通过get请求之后，通过then 来设置成功的回调函数
						this.$http.get('http://vue.studyit.io/api/getlunbo').then(function(result){
							//通过result.body 拿到服务器返回的成功的数据
							console.log(result.body)
						})
					},
					postInfo(){
						//发起post请求	application/x-from-urlencoded
						//手动发起的post请求，默认没有表单格式，所以，有的服务器是处理不了的。
						//通过post方法的第三个参数，{emulateJSON:true}设置提交的内容类型为普通表单数据格式
						this.$http.post('htttp://vue.studyit.io/api/post',{},{emulateJSON:true}).then(result=>{
							console.log(result.body)
						})
					},
					jsonpInfo(){
						this.$http.jsonp('http://vue.studyit.io/api/jsonp').then(result=>{
							console.log(result.body)
						})
					}
				}
			})
		</script>
	</body>
```

+ get请求
  + this.$http.get('http://vue.studyit.io/api/getlunbo').then(function(result){})
+ post请求
  + this.$http.post('htttp://vue.studyit.io/api/post',{},{emulateJSON:true}).then(result=>{})
+ jsonp请求
  + this.$http.jsonp('http://vue.studyit.io/api/jsonp').then(result=>{})