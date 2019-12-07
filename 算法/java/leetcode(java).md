# 1.字符串中的第一个唯一字符

#### 题目

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

**案例:**

```
s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
```

 

**注意事项：**您可以假定该字符串只包含小写字母。

#### 我的代码

```java
    static int firstUniqChar(String s) {
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (count[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
```

#### 我的理解

第一次写Java，有点迷，完全不会，发现虽然看了好多，但还有那么多自己不熟悉的东西。需要多看一看。

就这个程序而来，思想很简单，常见一个26的数组，每个元素对应一个字母，如果在字符串中遇到那个字母就给那个字母加一，最后直接通过直接访问字符串的每一个元素，判断那个元素先出现1次。从而得到结果。charAt()访问的是元素对应的char值，所以需要借用Char判断。

> count[s.charAt(i) - 'a']	这儿也应该注意。

#### 大佬的代码

```java
class Solution {
      public int firstUniqChar(String s) {
        int index = -1;
        //反过来，只有26个字符
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int beginIndex = s.indexOf(ch);
            // 从头开始的位置是否等于结束位置，相等说明只有一个，
            if (beginIndex != -1 && beginIndex == s.lastIndexOf(ch)) {
                //取小的，越小代表越前。
                index = (index == -1 || index > beginIndex) ? beginIndex : index;
            }
        }
        return index;
    }
}
```

#### 我对大佬代码的理解

给一个标志（如果符合条件，就用标志把值带出），从a到z开始判断，把字符串的每一个字母位置循环给beginIndex，然后判断beginIndex和对应字母最后一次出现的地方是否相同。最后判断，index是不是-1（如果是则说明之前的判断有问题，或者第一次循环）或者已经拿到的位置是不是大于我们现在拿到的位置，如果大于就说明之前的位置有问题，需要重新更新。

---

# 2. 有效的字母异位词 

#### 题目：

给定两个字符串 *s* 和 *t* ，编写一个函数来判断 *t* 是否是 *s* 的字母异位词。

**示例 1:**

```
输入: s = "anagram", t = "nagaram"
输出: true
```

**示例 2:**

```
输入: s = "rat", t = "car"
输出: false
```

**说明:**
你可以假设字符串只包含小写字母。

**进阶:**
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

#### 我的代码

```java
    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        boolean Boolean = true;
        int[] a = new int[26];
        int[] b = new int[26];
        for(int i = 0;i < s.length();i ++){
            a[s.charAt(i) - 'a'] ++;
            b[t.charAt(i) - 'a'] ++;
        }
        for (int j = 0 ;j < 26; j ++)
        {
            if (a[j] == b[j])
                continue;
            else
                Boolean = false;
        }
        return Boolean;
    }

```

#### 我的理解

这个题呢，暴力解题，哈哈！首先判断两个字符串是否相等，不相等直接返回错误。创建2个int数组，分别统计s和t中每个字母出现的次数。再逐个比较，如果有不相同的，false。否则就输出TRUE。运行竟然5ms，真快！

#### 大佬的代码

```java
    public boolean isAnagram(String s, String t) {
        int[] cnt = new int[26];

        for (char c: s.toCharArray()){
            cnt[c - 'a']++;
        }

        for (char c: t.toCharArray()){
            cnt[c - 'a']--;
        }

        for (int i : cnt){
            if (i != 0)
                return false;
        }
        return true;
    }
```

#### 我对大佬代码的理解

创建一个int数组。for出字符串s每一个元素，给数组对应位置加一。然后for出字符串t每一个元素，给数组对应位置减一。最后判断数组中的每个元素是不是0。如果不是那么就false。

我觉得可以这样写：

```java 
        for(int i = 0;i < s.length();i ++){
            a[s.charAt(i) - 'a'] ++;
            a[t.charAt(i) - 'a'] --;
        }
		for(int i : a){
            if(i != 0)
                return false;
        }
```

---

# 3.验证回文字符串

#### 题目

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

**说明：**本题中，我们将空字符串定义为有效的回文串。

**示例 1:**

```
输入: "A man, a plan, a canal: Panama"
输出: true
```

**示例 2:**

```
输入: "race a car"
输出: false
```

#### 我的代码

写了半天，最后还是错误满天飞，我跪了！

```java
    public static boolean isPalindrome(String s) {
        if (s.length() == 0)
            return true;
        s = s.toLowerCase();
        int last = s.length()-1;
        int pre = 0;
        int i;
        for (i = 0;i < s.length() / 2;i ++) {
            char flag1 = '*';
            while((flag1 == '*') && (pre < (last-1))) {
                if((s.charAt(pre) >= 'a' && s.charAt(pre) <= 'z') || (s.charAt(pre) >= '0' && s.charAt(pre) <= '9')) {
                    flag1 = s.charAt(pre);
                    pre++;
                }
                else
                    pre++;
            }
            char flag2 = '*';
            while((flag2 == '*') && (last > 0)) {
                if((s.charAt(last) >= 'a' && s.charAt(last) <= 'z') || (s.charAt(last) >= '0' && s.charAt(last) <= '9') ) {
                    flag2 = s.charAt(last);
                    last--;
                }
                else
                    last--;
            }
            if (flag1 != flag2) {
                return false;
            }
        }
        if (i == s.length()/2)
            return true;
        return false;
    }
```

#### 我的理解

设置两个指针，一个从字符串头向后，另一个从字符串尾向前。排除非字母数字，然后对比，如果有一个不相等，那么就false。但是问题就出到这儿了，变态输入，如果全部不是字母或者数字。这样就会出现问题。啊！我太难了！！！

#### 我改的代码

```java
    public static boolean isPalindrome(String s) {
        if (s.length() == 0)
            return true;
        s = s.toLowerCase();
        StringBuilder t = new StringBuilder();
        for (int i = 0;i < s.length();i ++){
            if ((s.charAt(i) >= 'a' && s.charAt(i) <= 'z') ||(s.charAt(i) >= '0' && s.charAt(i) <= '9'))
                t.append(s.charAt(i));
        }
        if (t.length() == 0)
            return true;
        int pre = 0;
        int end = t.length() - 1;
        while (pre < end) {
            if (t.charAt(pre) == t.charAt(end)) {
                pre++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
```

#### 我的理解

它首先利用StringBuilder的方法，直接把有效字符全部放入一个新的字符串中。然后再逐个比较。这个方法，真是好！

#### 大佬的代码

```java
public  boolean isPalindrome(String s) {
        if (s.length() <= 1)
            return true;
        int left = 0;
        int right = s.length() - 1;
        char[] chars = s.toCharArray();
        while (left < right) {
            //调整大写 A-Z 65-90 || a-z 97-122
            if ((int) chars[left] >= 65 && (int) chars[left] <= 90)
                chars[left] = (char) ((int) chars[left] + 32);
            if ((int) chars[right] >= 65 && (int) chars[right] <=90)
                chars[right] = (char) ((int) chars[right] + 32);
            //验证目标字符为数字或字母
            boolean flag1 = (chars[left] >= '0' && chars[left] <= '9') || (chars[left] >= 'a' && chars[left] <= 'z');
            boolean flag2 = (chars[right] >= '0' && chars[right] <= '9') || (chars[right] >= 'a' && chars[right] <= 'z');
            //正式比较
            if (flag1 && flag2 && chars[left] != chars[right]) {
                return false;
            }else if (!flag1){
                left++;
            }else if (!flag2){
                right--;
            }else {
                left++;
                right--;
            }
        }
        return true;
    }
```

#### 我对大佬代码的理解

get到一个知识点：把字符串转化成字符数组。

```java
char[] chars = s.toCharArray();
```

然后再进行操作。虽然时间用的短，但是代码有很多赘余。我觉得并不好。

---

# 4.字符串转换整数

#### 题目

请你来实现一个 `atoi` 函数，使其能将字符串转换成整数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

**说明：**

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231, 231 − 1]。如果数值超过这个范围，请返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。

**示例 1:**

```
输入: "42"
输出: 42
```

**示例 2:**

```
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
```

**示例 3:**

```
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
```

**示例 4:**

```
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
```

**示例 5:**

```
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
```

#### 我的代码

```java
	public static int myAtoi(String str) {
    	int n = str.length();
    	//字符串的长度
    	int i = 0;
    	//用于索引字符串的指针
    	while(i < n && str.charAt(i) == ' ') {
    		i ++;
    	}
    	//跳过空格
    	if(i == n||!((str.charAt(i) >= '0' && str.charAt(i) <= '9' )|| str.charAt(i) == '+' || str.charAt(i) == '-'))
    		return 0;
    	//判断是不是已经到达了字符串的顶端，判断当前索引位置的元素是不是【0，9】，‘+’，‘-’。
    	StringBuilder s = new StringBuilder();
    	//构造一个StringBuilder 的字符串。（StringBuilder中有很方便的字符串操作方法）。
    	if(str.charAt(i) == '-') {
    		s.append('-');
    		i ++;
    		//判断当前索引位置的元素是不是‘-’，如果是直接将其append进新建的字符串中。
    	}else if (str.charAt(i) == '+') {
    		i ++;
    		//判断当前索引位置的元素是不是‘+’，如果是就进入下一个索引的位置（正数我们没有必要再在前边加一个‘+’）。
    	}
    	if(i == n||!(str.charAt(i) >= '0' && str.charAt(i) <= '9' ))
    		return 0;
    	//再判断一次，如果超过字符串长度，那么直接结束。如果不是【0，9】那么直接返回0.
    	while(i < n && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
    		s.append(str.charAt(i));
    		i ++;
    	}
    	System.out.println(s);
    	try {
    		return Integer.valueOf(s.toString());
    	}catch(Exception e){
    		if(s.substring(0,1).equals("-")) {
    			return Integer.MIN_VALUE;
    		}else {
    			return Integer.MAX_VALUE;
    		}
    	}
    	//try……catch……，判断异常，抛异常时直接进入。
    	//valueOf()返回保存指定的 String 的值的 Integer对象。(java的number方法)
    	//equals,对比字符，必须用""。不然，不然就会跟我一样，花好长时间。
    	//substring(beging,ending)，获取字符串的【beging，ending）的
    }
```

#### 我的理解

```
这个题就是需要考虑很多的条件，
1.判断是不是空格开头，
2.判断第一个非空是不是“+”或者“-”
3.判断第一个是不是非数字
4.判断得到的数是否大于INT_MAX，或者小于INT_MIN
5.判断第一个非空不是正负号，不是数字时的处理。

valueOf(String s):返回保存指定的 String 的值的 Integer 对象。(java的number方法)
Integer.toString(): 返回表示 Integer 值的 String 对象。
	string.toString();
```

这个程序真的很有趣，它完全时一种全新的。我们一般都会想着在一个循环中解决问题，但是这个就是利用一个变量来把这个问题给解决了。详细注释在程序中！

#### 大佬的代码

```java
	public int myAtoi(String str) {
		if (str.isEmpty())
			return 0;
		char[] mychar = str.toCharArray();
		long ans = 0;
		int index = 0, flag = 1, n = str.length();
		//排除字符串开头的空格元素
		while (index < n && mychar[index] == ' ') {
			index++;
		}
		//排除空格后判断首字符是+还是-还是都不是
		if (index < n && mychar[index] == '+') {
			index++;
		} else if (index < n && mychar[index] == '-') {
			index++;
			flag = -1;
		}
		//重点：只管是数字的时候，其余取0
		while (index < n && (mychar[index] >= '0' && mychar[index] <= '9')) {
			if (ans != (int) ans) {//超出int范围
				return (flag == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;//提前结束
			}
			ans = ans * 10 + mychar[index++] - '0';
		}

		if (ans != (int) ans) {
			return (flag == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
		}

		return (int) (ans * flag);

	}
```

#### 我对大佬代码的理解

首先判断字符串是不是为空，如果是空，返回0。然后把字符串转化成字符数组。判断非空（拿到非空的位置）。再判断这个元素是不是“+”或者“-”，按找其对应的方法处理。然后判断后边的元素是不是在【0，9】，再判断结果有没有超出int范围，没超过则处理数据。最终再判断一次有没有超出【0，9】，再判断结果有没有超出int范围。最终输出得到的值。过程都比较复杂。

通过这个算法，get到了这种循环处理方式。

---

# 9.回文数

#### 我的代码

```java
	public static boolean isPalindrome(int x) {
		if(x < 0)
			return false;
		String s = (x + "");
		int pre = 0;
		int end = s.length() - 1;
		int i = 0;
		while(i < s.length()/2) {
			if(s.charAt(pre) == s.charAt(end)) {
				pre ++;
				end --;
			}else {
				return false;
			}
			i ++;
		}
		return true;
	}
```

#### 我的理解

```
回文数：
	1.回文数肯定不是负数。
	2.将回文数转化为字符串，然后直接进行字符串操作就可以对比出来。
```

排除负数。直接将回文数转化为字符串，然后逐个判断字符串的每一位。

#### 大佬的代码

```java
	public boolean isPalindrome(int x) {        
        if(x < 0 ){
            return false;
        }
        int original = x;
        int revs = 0;
        while(x != 0 ){
            revs = revs * 10 + x % 10;
            x = x / 10;
        }
        return original == revs;
    }
```

#### 我对大佬代码的理解

直接将回文数反转，然后互相比较。即可！

---

# 14.最长公共前缀

#### 我的代码

```java
	public static String longestCommonPrefix(String[] strs) {
	    if(strs.length == 0) 
	    	return "";
	    int lengths = strs[0].length();
	    for (int p = 1;p < strs.length;p ++) {
	    	if(lengths <= strs[p].length()) {
	    		continue;
	    	}else {
	    		lengths = strs[p].length();
	    	}
	    }
	    if(lengths == 0)
	    	return "";
		int i;
	    StringBuilder s = new StringBuilder();
	    s.append("");
	    for (i = 0;i < lengths;i ++) {
	    	char a = strs[0].charAt(i);
	    	int j = 1;
	    	while (j < strs.length) {
	    		if( a == strs[j].charAt(i)) {
	    			j ++;
	    			continue;
	    		}
	    		else {
	    			return s + "";
	    		}
	    	}
	    	if (j == strs.length) {
	    		s.append(a);
	    	}
	    }
		return s + "";
	}
```

#### 我的理解

这个玩意怎么说呢？挺简单的，但是需要考虑的东西挺多的。首先判断这个字符串是不是为空，如果为空直接返回“”；然后再判断得到字符数组中字符串的最短长度，创建一个StringBuilder字符串，然后再进行循环，判断字符串相同位置的字符是不是相同，如果相同继续比较下一个，如果不同返回String字符串。（在把所有字符串循环完之后，如果还没有退出，那么就append当前字符。）

```
将StringBuilder转化为String:
StringBuilder s = new StringBuilder();
String t = s + "";(这就是一个字符串。)
```

#### 大佬的代码

```java
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0){
            return "";
            //若字符串数组长度为0，直接返回“”；
        }
        String res=strs[0];
        //把字符串数组的第一个元素给res
        for(int i=1;i<strs.length;i++){
            //从字符串数组的1——>strs.length-1循环
            while(strs[i].indexOf(res)!=0){
                // 判断这个res字符串在不在strs[i]中
                res=res.substring(0,res.length()-1);
                // 
                if(res.length()==0){
                    return "";
                }
            }
        }
        return res;
    }
```

#### 我对大佬代码的理解

```
indexOf(String str): 返回指定字符在字符串中第一次出现处的索引，如果此字符串中没有这样的字符，则返回 -1。
substring() 方法返回字符串的子字符串。
```

有点尴尬，我看不懂！

---

