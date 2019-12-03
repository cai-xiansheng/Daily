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

