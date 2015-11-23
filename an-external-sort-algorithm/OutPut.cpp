/********************************************************
filename：		OutPut.cpp
author：		Mako Wan
date：	2014-3-27
description：		获得临时filename字符串，向二进制TempFile文件中写入数据
********************************************************/
#include "Head.h"
#include "OutPut.h"

/*
函数名：	TempFileName
功能：	获得临时filename字符串
输入：	临时filename的尾数
输出：   filename
*/
char * TempFileName(int Index){

	
	char* TempFile = new char[100];
	sprintf(TempFile, "TempFile%d", Index);
	return TempFile; // 返回临时filename
}

/*
函数名：	WriteData
功能：	向二进制TempFile文件中写入数据
输入：	参数1： 文件指针	参数2： 数据内存地址	参数3： 数据数量
输出：   filename
*/
void WriteData(FILE *TempFile, double *array, int n){

	int NumWrite = 0;
	NumWrite = fwrite(array, sizeof(double), n, TempFile);
}