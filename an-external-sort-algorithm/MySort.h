/********************************************************
filename：		MySort.h
author：		Mako Wan
date：	2014-3-21
description：		实现基数排序
********************************************************/
#ifndef MYSORT_H
#define MYSORT_H

union RadixData{

	double Dou;
	unsigned char Byte[sizeof(double)];

};

/*
函数名：	MySort
功能：	将double数进行基数排序
输入：	参数1： double数组	参数2： 浮点数数量
输出：   无
*/
void MySort(RadixData * DouBuf, int DouNums);
#endif