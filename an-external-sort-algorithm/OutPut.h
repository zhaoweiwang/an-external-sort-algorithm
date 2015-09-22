/********************************************************
文件名：		TempFileName.h
创建人：		zhaoweiwang
加注日期：	2014-3-21
描述：		获得临时文件名字符串
********************************************************/
#ifndef TEMPFILENAME_H
#define TEMPFILENAME_H
/*
函数名：	TempFileName
功能：	获得临时文件名字符串
输入：	临时文件名的尾数
输出：   文件名
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