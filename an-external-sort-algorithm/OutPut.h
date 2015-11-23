/********************************************************
filename：		TempFileName.h
author：		Mako Wan
date：	2014-3-21
description：		获得临时filename字符串
********************************************************/
#ifndef TEMPFILENAME_H
#define TEMPFILENAME_H
/*
函数名：	TempFileName
功能：	获得临时filename字符串
输入：	临时filename的尾数
输出：   filename
*/
char * TempFileName(int Index);

/*
函数名：	WriteData
功能：	向二进制TempFile文件中写入数据
输入：	参数1： 文件指针	参数2： 数据内存地址	参数3： 数据数量
输出：   无
*/
void WriteData(FILE *TempFile, double *array, int n);

#endif