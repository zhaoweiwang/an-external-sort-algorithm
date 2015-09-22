/********************************************************
文件名：		MySort.cpp
创建人：		zhaoweiwang
加注日期：	2014-3-21
描述：		实现基数排序
********************************************************/
#include "Head.h"
#include "MySort.h"

/*
函数名：	MySort
功能：	将double数进行基数排序
输入：	参数1： double数组	参数2： 浮点数数量
输出：   无
*/
void MySort(RadixData * DouBuf, int DouNums){

	union RadixData * Data = new RadixData[DouNums];

	const int BitNums = 256;

	int Count, Byt[BitNums];

	for(int i = 0; i < DouNums; i++){
	
		if(DouBuf[i].Dou >= 0)
			DouBuf[i].Byte[7] += 128;	//将正数的符号位赋为1
		else
			for(int j = 0; j < sizeof(double); j++)
				DouBuf[i].Byte[j] = ~(DouBuf[i].Byte[j]);	//将负数按位取反
	}

	for(int i = 0; i < sizeof(double); i++){
	
		RadixData * Temp = Data;
		Data = DouBuf;
		DouBuf = Temp;

		for(int j = 0; j < BitNums; j++)
			Byt[j] = 0;	//初始化

		for(int j = 0; j < DouNums; j++)
			Byt[Data[j].Byte[i]]++;	//记录每个字节等于Number的浮点数

		Byt[BitNums - 1] = DouNums - Byt[BitNums - 1];

		for(int j = BitNums - 1; j > 0; j--)
			Byt[j - 1] = Byt[j] - Byt[j - 1];

		for(int j = 0; j < DouNums; j++){
		
			Count = Byt[Data[j].Byte[i]];
			Byt[Data[j].Byte[i]]++;
			DouBuf[Count].Dou = Data[j].Dou;
		}
	}

	delete []Data;

	for(int i =0; i < DouNums; i++){
	
		if(DouBuf[i].Dou <= 0)
			DouBuf[i].Byte[7] -= 128;
		else
			for(int j = 0; j < sizeof(double); j++)
				DouBuf[i].Byte[j] = ~(DouBuf[i].Byte[j]);
	}	//对负数的符号位赋为0，将正数按位取反
}