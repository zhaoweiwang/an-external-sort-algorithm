/********************************************************
filename：		MemorySort.h
author：		Mako Wan
date：	2014-3-21
description：		外排程序的读取数据模块，实现读取数据块功能；
********************************************************/

#ifndef MEMORYSORT_H
#define MEMORYSORT_H
/*
函数名：	MemorySort
功能：	读取数据，为内排数据做准备挨
输入：	排序文件的filename
输出：   文件块数量，同时也是K路归并的K路值
*/
int MemorySort(/*PathType*/ char * InFileName, char * OutFileName);
#endif