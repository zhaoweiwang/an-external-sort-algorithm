# an-external-sort-algorithm
An implement case: external sort algorithm with 250 million double-precision floating-point number using C++.

**keywords:**  external-sort multithreading dou2str radix-sorting merge-sort tree-of-loser high-precision block-fetch



### **缺点**

1. 没有必要一个头文件（.h）对应一个源文件（.cpp），意义不大，反而造成定义在各个头文件中的全局参数引用混乱；
2. 代码不简练，一个是由于C操作用得多，相较于C++11中的vector、以及各式各样的stl库函数的方便而言，语言的局限性导致；另一个是当时能力有限，用了很多笨方法和编码习惯；