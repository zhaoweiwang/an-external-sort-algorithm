# an-external-sort-algorithm

**An implement case: external sort algorithm with 250 million double-precision floating-point number (by C++).**

**keywords:**  external-sort multithreading dou2str radix-sorting merge-sort tree-of-loser high-precision block-fetch

1. 问题描述：
输入文本由符合 IEEE 754 标准的 64 位的十进制浮点数构成，每两个浮点数之间以空格或者横向制表符或者换行符间隔，间隔符只有一个。不符合以上描述的文本都是非法字符。例如输入文本 input.txt： 内容如下（可能不标准，而且含有非法字符）：

```C++
3.14159268
6.62e-134
6.12345678E-11
0.618
-1000000
hello
```

输出文本是对输入文本排序后的结果，每个结果独占一行，需严格符合IEEE 754标准（特别要求：精确到小数点后17位），输出为普通的文本格式。非法字符可以删除，但须记录非法字符数目。理论上来说，不管谁实现的程序，对于相同的输入文本，输出的文本应该是一模一样的。例如以上的 input.txt 的输出结果应该是：

```C++
-1.00000000000000000E+006
6.62000000000000000E-134
6.12345678000000000E-011
6.18000000000000000E-001
3.14159268000000000E+001
```
##2. 内核模块##

###2.1 读取数据###

这里需要注意一件事情，由于记录会有上亿条，因此不能用行读取方式读取数据，在百万数据时因为 I/O 次数频繁，时间即已破千。同时，判断浮点数是否合法也不能采用正则表达式，因为正则表达式同样极为耗时。为了减少 I/O 次数，应采用 fread() 函数进行较大数据块方式（因内存限制是500M，因此这里可以一次读取200M）读取文件记录。

**接着会遇到两个问题：**

（1）如何对内存中的字符串判断其是否为合法的双精度浮点数？

（2）如何将判断得到的双精度浮点数字符串转换为浮点数？

**解决方法：**

判断是否遇到制表符、换行符和空格符等，然后截取子字符串，随后利用自己写的 [judge()](https://github.com/zhaoweiwang/an-external-sort-algorithm/blob/master/an-external-sort-algorithm/Str2Dou.cpp) 函数判断其是否为合法浮点数，是则将其用自己写的 [Str2Dou()](https://github.com/zhaoweiwang/an-external-sort-algorithm/blob/master/an-external-sort-algorithm/Str2Dou.cpp) 函数将合法的str转化成double数。判断和转换的逻辑还是比较复杂，转换时需要注意逻辑。



### 时间： ###

一百万：0.861秒

一千万：7.087秒

五千万：43.69秒

二点五亿：211.707秒
