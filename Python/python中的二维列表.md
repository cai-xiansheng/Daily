# python中的二维列表

今天在一个问题中遇到了二位列表，之前也没有注意这个。

它的访问还是跟C语言中的二维数组类似。

```python
board = [][]
board = [[1,2,3],[4,5,6],[7,8,9]]
# 访问行
board[i]
# 访问行元素
for flag in board[i]:
# 访问列
li = [p[i] for p in board]
# 也可以通过board[i][j]访问。
```

