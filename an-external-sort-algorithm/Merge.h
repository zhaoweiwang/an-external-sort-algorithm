/********************************************************
filename：		Merge.h
author：		Mako Wan
date：	2014-3-21
description：		K路归并算法
********************************************************/
#ifndef MERGE_H
#define MERGE_H
/*
函数名：	Merge
功能：	K路归并
输入：	参数1： 数组[K+1]    参数2：文件数    参数3： 败者树 参数4： 输出filename
输出：   无
*/
void Merge(double *b, int FileNums, int *ls, char * OutFileName);
#endif