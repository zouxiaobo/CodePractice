## 二进制中1的个数

### 题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。   

****
** 以下代码均经测试通过,可直接运行 **   

### 思路
首先，负数转为正数去判断，最后结果+1即可；   
然后，将数不断右移与1按位与，结果不为0则1的个数+1。

```
int  NumberOf1(int n) 
{
	if(0 == n)
	{
		return 0;
	}

	bool bIsPosi = n>0?true:false;
	unsigned int u1Cnt = 0;
	int iTarget = 0x7FFFFFFF&n;	//这里我之前写的是iTarget = n>0?n:-n;
	/*
	 * 这里要特别注意，计算机中，负数是补码表示，-n的相反数n与0x7FFFFFFF&n的值是不同的    
	 * 我那种相反数的写法是错误的  
	*/

	while(0 != iTarget)
	{
		if(0x1 & iTarget)
		{
			u1Cnt++;
		}

		iTarget = (iTarget >> 1);
	}

	return (bIsPosi?u1Cnt:u1Cnt+1);
}
```
   
思路二：n不变，通过把1不断左移与n按位与
```
int  NumberOf1(int n) 
{
	if(0 == n)
	{
		return 0;
	}

	unsigned int u1Cnt = 0;
	int flag = 1;
	for(int i=0; i<32; i++)
	{
		if(n&flag)
		{
			u1Cnt++;
		}
		flag = flag << 1;
	}

	return u1Cnt;
}

```


### 总结
我自己只想到了思路一，思路二没想到。

负数变正数并不是简单的变为相反数，这个要看具体的目的，这题我想到了负数转为正数，就条件反射想到了加个负号，其实在计算机中**负数表示是补码**，变为正数并不是相反数，造成这种误解的原因可能是负数的补码是原码即取反+1，例如-3的补码是这样推导的
原码：1000...0011(最高位符号位，其余按照相反数[绝对值]表示)
反码：1111...1100
补码：1111...1101   

乘数法的话**位运算**效率高很多   
