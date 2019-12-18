
reset.css（重置某些元素的不必要属性）
    
    块元素的外边界在我们使用中并不需要，所以对他们尽行置零处理。
        例如：
            body,p,h1,h2{
                margin:0;
            }

    img标签在IE浏览器中会出现边框，所以将边框删除。
        例如：
            img{
                border:none;
            }
        img还有一个属性，就是将图片竖直方向剧中：
            vertical-align:middle;
    
    a标签中对他的文本会由下面一个底色，看起来并不好看，需要我们将它去掉。
        例如：
            a{
                text-decoration:none;
            }
            
    ul标签中会出现那个小圆点，但在实际使用中我们并不需要它(他也有内外边界)：
        ul{
            list-style:none;
            margin:0;
            padding:0;
        }
层级属性之间的相互作用

    比如说：line-hight:1.5;
            line-hight:150%;
        这两个分别放在外层，会有不同的效果。
        例：
            body{
                font-size:14px;
                line-hight:1.5;
            }
            p{
                font-size:20px;
            }
            在这儿p的font-size将会用1.5*20px=30px;并不会理睬body中的font-size。
        
        例：
             body{
                font-size:14px;
                line-hight:150%;
            }
            p{
                font-size:20px;
            }
            在这儿p的font-size将会用14*150%*20px；意思就是它先将body里面的font-size与line-hight处理一下，再将传到p中进行计算。
            
字体

    font-family:''<!--里面的内容可以用名称，也可以用字体对用的编码。-->
    
主色调

    例如：
        .c4{    <!--淘宝红-->
            color:#f40;
        }
        
    在用的之后直接引用class就可以直接解决了，不用重复定义color:#f40;
    
    不仅有色调，还有常用的样式。都可以用预定义class.
    
模块化

    @import     导入其他样式文件（样式模块化）
    
base

    base可以定义基础东西
    例如：<base href="url"/>
          <base target="_blank">
        
        但是base只能只能出现一个
        
