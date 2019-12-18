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

