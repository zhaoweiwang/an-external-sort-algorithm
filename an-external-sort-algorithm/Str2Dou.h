/********************************************************
文件名：		Str2Dou.h
创建人：		zhaoweiwang
加注日期：	2014-3-27
描述：		实现判断字符串为合法字符串，并将其转化为double数据；
********************************************************/
#ifndef STR2DOU_H
#define STR2DOU_H
/*
函数名：	Str2Dou
功能：	将数据块中的字符串转换成double数
输入：	参数1：字符串数据块	参数2：double数据块
输出：   返回double数组中的数据量
*/
int Str2Dou(char * DataBuf, double * DouBuf);
/*
函数名：	Str2DouPro
功能：	具体字符串转浮点数
输入：	参数1：字符串
输出：   返回double数
*/
double Str2DouPro(const char * StrTemp);
#endif