# 1.从排序数组中删除重复项
#### 我的代码：
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
#### 我的思路：

刚开始没有考虑到列表中一个数或者两个相同数的问题，直到后面测试案例测出来，我才发现。我想一个一个检测，因为题目中给出的测试输入是有规律的，我这个算法也就只能在这种环境下才能运行。先测除数组的长度，用做while循环的条件，然后先判断长度为0，1的数组，如果遇到这种情况直接结束，返回测得的长度。如果不满足继续执行。主要的内容就是，先把第一个数拿出来，然后把这个数添加到最后一位，再删除第一个数。以后每次，先判断第一个数是否和最后一个数相同，若相同直接删除第一个数，结束本次循环；若不是，就把这个数还是存到最后一个，然后再删除第一个。依次循环，直到while循环结束。
#### 大佬的代码：

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
#### 我对大佬代码的理解：
先判断数组的长度是不是1或者0，如果这样就返回他们的长度。然后定义一个位置i，一个计数（初值给1），然后把第一个数给flag，然后依次循环比较第i个数和flag是否相同，如果相同，就把给i += 1，若果不同就把这个数给flag，然后给j +=1。直到循环结束。返回计数j。666
		
---

# 2.买卖股票的最佳时机II
#### 我的思路：
说实话，这个我虽然想了半天，但还是在实现的时候出现了障碍，总之还是逻辑上的问题。
#### 看完大佬的思路，我的思路：
做什么事只关注眼前利益，从第一天开始（忽略第0天）。如果今天的利润减去昨天的利润为正，那么昨天就买入，然后今天卖出（这样就防止亏本），并把利润差统计出来；到明天的时候再进行这样的判断，进行循环操作，直到最后一天。并不需要给顶什么标志，再循环比较（我的思路就是这样！）。
#### 我的代码：

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
#### 大佬的代码：

```python
		def maxProfit(self, prices: List[int]) -> int:
			profit = 0
			for i in range(1, len(prices)):
				if prices[i] > prices[i - 1]:
					profit += (prices[i] - prices[i - 1])
			return profit
```
#### 我对大佬代码的理解：
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