## 数值的整数次方

### 题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。   
保证base和exponent不同时为0

****
** 以下代码均经测试通过,可直接运行 **   

### 思路
分为以下几种情况：
base =0
exp = 0
exp < 0  按照大于0处理，最后结果再与1做除法
exp > 0
时间复杂度：O(n)
```
double Power(double base, int exponent)
{
    if(base == 0)
    {
        return 0;
    }
    if(exponent == 0)
    {
        return 1;
    }

    bool bIsPosi = exponent>0?true:false;
    double dRes = 1.0;
    int iAbsVal = bIsPosi?exponent:-exponent;

    for(int i=0; i<iAbsVal; i++)
    {
        dRes = dRes*base;
    }

    return bIsPosi?dRes:(1.0/dRes);
}
```
思路2
这种思路我没有想到，使用递归，时间复杂度O(logn)   
当n为偶数，a^n =（a^n/2）*（a^n/2）   
当n为奇数，a^n = a^[(n-1)/2] * a^[(n-1)/2] * a   
这里暂时不写，看以后自己还写得出这个递归嘛，哈哈哈，总觉得自己很不太会写递归   
```
double Power(double base, int exponent)
{
    if(base == 0)
    {
        return 0;
    }
    if(exponent == 0)
    {
        return 1;
    }


}
```


### 总结
在做乘数法、取余等运算时，可考虑使用位运算，这样效率高很多   
