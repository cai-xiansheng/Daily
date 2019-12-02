# 1.字符串中的第一个唯一字符

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