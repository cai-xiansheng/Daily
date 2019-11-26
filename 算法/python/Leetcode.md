# 1.从排序数组中删除重复项

#### 我的代码
```python
		from typing import List
		def ppo(nums:List[int]) -> List[int]:
			lenth = len(nums)
			if lenth == 0 or lenth == 1:
				return lenth
			i = 0
			while i < lenth:
				if nums[-1] == nums[0] and len(nums) != 1:
					i += 1
					del nums[0]
					continue
				now = nums[0]
				del nums[0]
				nums.append(now)
				i += 1
			outLenth = len(nums)
			return outLenth
```
#### 我的思路

刚开始没有考虑到列表中一个数或者两个相同数的问题，直到后面测试案例测出来，我才发现。我想一个一个检测，因为题目中给出的测试输入是有规律的，我这个算法也就只能在这种环境下才能运行。先测除数组的长度，用做while循环的条件，然后先判断长度为0，1的数组，如果遇到这种情况直接结束，返回测得的长度。如果不满足继续执行。主要的内容就是，先把第一个数拿出来，然后把这个数添加到最后一位，再删除第一个数。以后每次，先判断第一个数是否和最后一个数相同，若相同直接删除第一个数，结束本次循环；若不是，就把这个数还是存到最后一个，然后再删除第一个。依次循环，直到while循环结束。
#### 大佬的代码

```python
		def removeDuplicates(self, nums: List[int]) -> int:
			if len(nums) == 1:
				return 1
			if not nums:
				return 0
			i = 0
			j = 1
			flag = nums[i]
			while(i<len(nums)):
				if nums[i] == flag:
					i += 1
				else:
					flag = nums[i]
					nums[j] = flag
					j += 1
					i += 1
			return j
```
#### 我对大佬代码的理解
先判断数组的长度是不是1或者0，如果这样就返回他们的长度。然后定义一个位置i，一个计数（初值给1），然后把第一个数给flag，然后依次循环比较第i个数和flag是否相同，如果相同，就把给i += 1，若果不同就把这个数给flag，然后给j +=1。直到循环结束。返回计数j。666
		
---

# 2.买卖股票的最佳时机II
#### 我的思路：
说实话，这个我虽然想了半天，但还是在实现的时候出现了障碍，总之还是逻辑上的问题。
#### 看完大佬的思路，我的思路
做什么事只关注眼前利益，从第一天开始（忽略第0天）。如果今天的利润减去昨天的利润为正，那么昨天就买入，然后今天卖出（这样就防止亏本），并把利润差统计出来；到明天的时候再进行这样的判断，进行循环操作，直到最后一天。并不需要给顶什么标志，再循环比较（我的思路就是这样！）。
#### 我的代码

```python
		from typing import List
		def maxProfit(prices: List[int]) -> int:
			i = 1
			maxp = 0
			while i < len(prices):
				if prices[i-1]<prices[i]:
					sum = prices[i] - prices[i - 1]
					if sum > 0:
						maxp = maxp + sum
				i += 1
			return maxp
```
#### 大佬的代码

```python
		def maxProfit(self, prices: List[int]) -> int:
			profit = 0
			for i in range(1, len(prices)):
				if prices[i] > prices[i - 1]:
					profit += (prices[i] - prices[i - 1])
			return profit
```
#### 我对大佬代码的理解
还是从第一天开始的（忽略第0天），如果今天利润大于昨天的利润，就把利润差累加给总利润。真是简单！666我真菜！！！

---
# 3.旋转数组
#### 我的代码

```python
from typing import List
def rotate(nums: List[int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    i = 0
    while i<k:
        nums.insert(0,nums.pop())
        i += 1
```
#### 我的理解
直接用进出列表来解决这个问题，移动次数用循环控制。哈哈，这么快就做出来了。但我看到我的运行时间时，我懵了：188ms，这应该是我的算法运行时间最长的了。看来操作进出队列，真是费时间。

#### 大佬的代码
```python
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums[:] = nums[len(nums) - k % len(nums):] + nums[:len(nums) - k % len(nums)]
```
#### 我对大佬代码的理解：
太牛逼了，一行解决战斗！他直接将列表按照我们给的K值切断，然后重新组合，切断时利用取余，把多次循环按照列表长度以内的的长度处理（就是如果重复循环了，就按照最后一波的处理），然后把后面的添加到前边，前边的放到后边。nums是他利用的一个变量。后边的是我们之前传递过来的。

需要注意的是：列表的索引是从0开始的。nums[:] = ···  这是克隆相同的列表。


| 索引 | data |
| ---- | ---- |
| 0    | 1    |
| 1    | 2    |
| 2    | 3    |
| 3    | 4    |
| 4    | 5    |
| 5    | 6    |

---

# 4.存在重复

#### 我的代码

```python
def containsDuplicate( nums: List[int]) -> bool:
    i = 1
    while i < len(nums):
        if nums[i - 1] in nums[i:]:
            return True
        i += 1
    return False
```

#### 我遇到的问题
这个如果遇到大量数据，操作时间太长，少量数据可以使用。
#### 我改的代码

```python
def containsDuplicate( nums: List[int]) -> bool:
    if len(nums) <= 1:
        return False
    i = 1
    nums.sort()
    while i < len(nums):
        if nums[i-1] == nums[i]:
            return True
        i += 1
    return False
```
#### 我的理解
这个问题怎么说呢，想解决这个问题很简单，但是在效率面前，代码的操作真的很有必要注意。
刚开始我的想法是：直接进行出列表操作，然后在判断这个flag是不是还在列表里面，如果在true，反之false。但是这个存在的问题，首先进行了列表的删除操作，随后还得把每个元素跟剩余的列表进行对比操作，耗费时间太多。（我的CPU竟然会跑满！！）
看完思路后：直接对列表进行sort()操作，然后直接左右对比。与之前我的相比，时间耗费大量下降。
#### 大佬的代码

```python
    def containsDuplicate(self, nums: List[int]) -> bool:
        s = set(nums)
        if len(s) == len(nums):
            return False
        else:
            return True
```
#### 我对大佬代码的理解
 ***set()*** 这个方法就是把一个列表直接进行排序（按照ASCLL排序），并且删除重复项，重复项只保留一个。

 操作：s = set(nums)    这就是将nums排序后放入s，

 他进行了set()，然后就直接对比s与nums的长度。显而易见，如果长度减小，就说明存在重复项。

---

# 5.只出现一个数字
#### 我的代码
```python
from typing import List
def singleNumber(nums: List[int]) -> int:
    i = 0
    while i < len(nums):
        flag = nums.pop(0)
        if flag in nums:
            nums.remove(flag)
            continue
        else:
            return flag
```
#### 我的想法
还是进行列表操作，但是这个操作太耗费时间，用了2000多ms。需要改善！
#### 我更改后的
```python
from typing import List
def singleNumber(nums: List[int]) -> int:
    i = 0
    nums.sort()
    while i < len(nums):
        flag = nums[i]
        if flag in nums[i+1:]:
            i += 2
            continue
        else:
            return flag
```
#### 我的反思
后面的这个运算时间600多ms，哈哈，还算是有提高。这个就只是对列表进行了排序操作，然后进行循环判断，如果成立++2。之前写的那个对列表进行了操作，但是太好费时间了，总之还是直接对比好，不要使劲操作列表！！！还有sort(),in都会进行大量操作，跟数据量是成正比的。
#### 大佬的代码
```python
    def singleNumber(self, nums: List[int]) -> int:
        size = len(nums)
        ans = nums[0]
        for i in range(1, size):
            ans ^= nums[i]
        return ans
```
#### 我对大佬代码的理解
他这个就是利用^的特征，如果两个数相同就会是0，反之就是它们自己相加。题目中说到会有一个元素出现2次，还会有一个出现一次。所以说若出现两次就是0，出现一次的就是它本身，太牛皮了！这个只有线性时间复杂度。并且操作简单。

a^=b 相当于：a=a^b；
异或就是两个数的二进制形式，按位对比，相同取0，不同取1，然后相加赋值给a.

range按位计数，range[1,5]，它只会产生[1,2,3,4]

---
# 6.两个数组的交集 II
#### 我的代码
```python
from typing import List
def intersect( nums1: List[int], nums2: List[int]) -> List[int]:
    nums1.sort()
    nums2.sort()
    i = 0
    j = 0
    s = []
    while i < len(nums1) and j < len(nums2):
        if nums1[i] == nums2[j]:
            s.append(nums1[i])
            i += 1
            j += 1
        elif nums1[i] < nums2[j]:
            i += 1
        else:
            j += 1
    return s
```
#### 我遇到的问题
我之前改了好长时间，都是因为指针移动的问题，要么移动距离小了，要么移动距离大了，这都是问题。还有很容易就超出范围了。
#### 我的理解
在写了一个小时没有效果后，在网上看了看，写了出来。

这个主要就是对指针的移动做出了很好的限制。先给列表进行sort()排序，然后进行指针的跳转。指针变化的过程如下：（1）.首先列表操作的条件就是不能超过任何一个列表的长度。（2）.然后就是判断，如果两个一样大，就把这个值加给另外一个列表，反之将小的值的列表的指针加一，再次循环。

很简单的一个方法，主要得从全局考虑，不要死抓者一个点不放过，如果有问题，并且长时间都解决不了，就直接从题目入手，用其他方法解决这个问题。
#### 大佬的算法
```python
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        if len(nums1) > len(nums2):
            return self.intersect(nums2, nums1)
        freq_dict = dict()
        result = []
        for i in nums1:
            if i in freq_dict:
                freq_dict[i] = freq_dict[i] + 1
            else:
                freq_dict[i] = 1
                
        for i in nums2:
            if i in freq_dict:
                result.append(i)
                freq_dict[i] -= 1
                if freq_dict[i] == 0:
                    freq_dict.pop(i)
        
        return result
```
#### 我对大佬代码的理解
首先进行判断，将长度小的列表放到前边，这样可以减小循环次数。
然后后面我看不懂了！！！

其实我感觉我看完思路后写出的那个还是想到好的，毕竟效率高的代码，我看不懂这也是个问题。

---
# 7.加一

#### 我的代码
```python
from typing import List
def plusOne(digits: List[int]) -> List[int]:
    i = len(digits) - 1
    digits[-1] += 1
    while i >= 0:
        if digits[i] > 9:
            if i == 0:
                digits[i] = 0
                digits.insert(0,1)
            else:
                digits[i] = 0
                digits[i-1] += 1
        i -= 1
    return digits
```
#### 我的理解

首先得到列表的长度，然后给最后一位加1。在循环结构中逆序循环，从最后一位向前循环，如果这位的数字大于9那么就给上一位加一（如果到了索引0的位置，我们还需要进位，那么就使用方法insert(0,1)，这样就可以解决进位溢出的问题。）。

#### 大佬的代码

```python
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = digits[::-1]
        n = len(digits)
        c = 1
        index = 0
        while c == 1 and index < n:
            t = (digits[index] + c) % 10
            c = (digits[index] + c) // 10
            digits[index] = t
            index += 1
        if c == 1:
            digits.append(1)
        return digits[::-1]
```

#### 我对大佬代码的理解

首先进行转置处理，将列表反向排序，然后给一个变量给定一个值1，然后进行加一操作。从第一位开始，如果这儿的数加上1，得到的数是10，那么就会再次给变量赋值1 。如果这个变量是1才进行下次操作，若不是直接结束操作。若加完后有溢出，就在最后给列表的最后一位append(1)。这样就可以解决溢出。最后在返回值时将列表再次反转就可以完成操作。

这个算法在没有进位时直接就退出循环了，然而我的那个程序依然还在循环。所以说标识符还是非常重要的。在类似的循环中设置标识符，可以减少循环次数，提高运行效率。

---

# 8.移动零
#### 我的代码
```python
from typing import List
def moveZeroes( nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    j = 0
    i = 0
    while i < len(nums):
        if nums[i] == 0:
            nums.remove(0)
            j += 1
        else:
            i += 1
    while j > 0:
        nums.append(0)
        j -= 1
```
#### 我的理解
统计列表中0的个数，同时删除这个0。然后再给列表的尾部添加相同个数的0。在这个过程中，我遇到了一个问题，之前理解的remove()是将列表元素中的某个元素全部删除，然而是将某个元素第一次出现的删除。并不做全部处理。

>remove()删除列表中一个元素的第一个，并不能删除列表中那个元素的所有。下面一个例子。
```python
a = [1,0,1,0]
a.remove(0)
a = [1,1,0]
```
#### 大佬的代码
```python
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        loc = 0
        for num in nums:
            if num != 0:
                nums[loc] = num
                loc += 1
        while loc < len(nums):
            nums[loc] = 0
            loc += 1
```
#### 我对大佬代码的理解
遍历列表中的元素，设置一个索引元素，如果这个元素不为0，那么就将这个元素给列表的0号位置，以此类推，把列表中所有的0就排除了。随后，判断列表的索引是否达到列表的长度，如果没有达到，就给最后几个元素，赋值0。这样操作不用重复删除，分配空间了，仅仅是操作列表中的元素，所以提高了效率。

---

# 9.两数之和
#### 我的代码
```python
from typing import List
def twoSum( nums: List[int], target: int) -> List[int]:
    arr = []
    for i in range(0,len(nums)):
        for j in range(i + 1,len(nums)):
            if i != j:
                if nums[i] + nums[j] == target:
                    arr.append(i)
                    arr.append(j)
                    return arr
    return arr
```
#### 我的理解
刚理解题目的时候理解错题意了，题目中要求是两个元素不同（那就是不在同一个位置上。），我却理解成了，元素的值不能相等。

不仅如此，这次还是出现了我最不想见到的“大数据”，数据太多了，简单方法处理起来太耗费时间了，我也是醉了。最终终于以6000多ms的速度通过了。但还是太耗费时间了。
#### 大佬的代码
```python
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for index, num in enumerate(nums):
            //遍历nums元素的索引和元素
            find = target - num
            //将target减去num的数赋给find
            if find in dic:
            //判断find的值是不是在字典中。
                return [dic[find], index]
                //如果在，就将已经存在的元素索引和刚循环到的索引返回，但前提条件是必须字典中必须存在find（find就是字典中的keys）
            else:
                dic[num] = index
                //这个就是不成立的条件下往字典中存数据的操作。
```
#### 我对大佬代码的理解
>enumerate(列表)    这个方法它会给我们逐个返回中的【元素的索引】和【元素】

>enumerate 这个方法经常被用在for循环中，我们将拿到的【元素的索引】和【元素】进行处理。
```python
names = ['al','op','ko']
for index, data in enumerate(names):
```
上面的方法就是利用enumerate遍历列表中的【元素的索引】和【元素】，然后判断【target - data】的差值是不是在字典中，如果不在字典中，就将keys-values对应为【元素】-【元素的索引】存入字典中。如果在字典中，就将那个差值对应的索引和遍历到的元素的索引当成一个列表return返回。

---

