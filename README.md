# an-external-sort-algorithm
** An implement case: external sort algorithm with 250 million double-precision floating-point number(by C++). **

**keywords:**  external-sort multithreading dou2str radix-sorting merge-sort tree-of-loser high-precision block-fetch

**数据：**
```C++
3.603860899499E-268
3.744261471778E-225
2.071964576425E74
1.241726032488E138
-5.7571698334E-134
-2.53761210755E144
```

**时间：**
一百万：0.861秒
一千万：7.087秒
五千万：43.69秒
二点五亿：211.707秒

### **缺点**

1. 没有必要一个头文件（.h）对应一个源文件（.cpp），意义不大，反而造成定义在各个头文件中的全局参数引用混乱；
2. 代码不简练，一个是由于C操作用得多，相较于C++11中的vector、以及各式各样的stl库函数的方便而言，语言的局限性导致；另一个是当时能力有限，用了很多笨方法和编码习惯；
3. 没有必要使用传参形式来共享变量，为了提升速度直接采用全局变量即可。特别是内存占用较大的缓冲区，即使是引用传参，对速度的影响也较为明显，当时没有考虑到这一点。