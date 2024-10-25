# CS-MEDIUM-01 大数运算 

## Part 1 理解大数运算

1. **为什么要使用字符数组来表示大数？**
	1. 表示范围更大：`int`是32位整数，`long long`是64位整数，当需要处理更大位数时不够用，而采用字符数组，理论上可以表示任意大小的数； 
	2. 容易实现四则运算：可以通过遍历数组并逐位进行计算来实现加法、减法、乘法和除法； 


2. **如何处理大数运算中的进位和借位问题？**

	引入变量carry，前一位相加大于等于1时，赋值carry = 1，加入下一位的计算；前一位相加小于1时，赋值carry = 0，加入下一位的计算。前一位相减大于等于0时，赋值carry = 0加入下一位的计算；前一位相减小于时，赋值carry = -1加入下一位的计算；

3. **如何处理负数？**

	- 大数加法和减法：去负号转化成绝对值之间的加减，最后通过大小比较确定是否在结果前添加负号。 

	- 大数乘法和出发：去负号转化成绝对值之间的乘除，最后通过

		```text
		负数乘以负数得正数，负数除以负数得正数。
		正数乘以负数得负数，正数除以负数得负数。
		两个正数相乘得正数，两个正数相除得正数。
		```

		确定是否在结果前添加负号。



## Part 2 初步实现大数运算

#### Step 1 尝试存储大数

1. 代码见bigNumberStore.c 
2. 图片见bigNumberStore.png 

#### Step 2 实现大数加法

1. 代码见bigNumberAdd.c 
2. 图片见bigNumberAdd.png 

### Step 3 实现大数加法（处理负数）

1. 代码见bigNumberAddPro.c
2. 图片见bigNumberAddPro.png 



## Part 3 从表达式中提取操作数和操作符

1. 代码见getBigNumberAndOperator.c 
2. 图片见getBigNumberAndOperator.png 



## Part 4 封装大数四则运算

1. 代码见bigNumberCalculate.c 
2. 图片见bigNumberCalculate.png

