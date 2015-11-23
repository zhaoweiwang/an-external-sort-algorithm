/********************************************************
filename��		MySort.cpp
author��		Mako Wan
date��	2014-3-21
description��		ʵ�ֻ�������
********************************************************/

#include "Head.h"
#include "MySort.h"

/*
��������	MySort
���ܣ�	��double�����л�������
���룺	����1�� double����	����2�� ����������
�����   ��
*/
void MySort(RadixData *DouBuf, int DouNums){

	union RadixData *Data = new RadixData[DouNums];

	const int BitNums = 256;

	int Count, Byt[BitNums];

	for(int i = 0; i < DouNums; i++){
	
		if(DouBuf[i].Dou >= 0)
			DouBuf[i].Byte[7] += 128;						//�������ķ���λ��Ϊ1
		else
			for(int j = 0; j < sizeof(double); j++)
				DouBuf[i].Byte[j] = ~(DouBuf[i].Byte[j]);	//��������λȡ��
	}

	for(int i = 0; i < sizeof(double); i++){
	
		RadixData * Temp = Data;
		Data = DouBuf;
		DouBuf = Temp;

		for(int j = 0; j < BitNums; j++)
			Byt[j] = 0;

		for(int j = 0; j < DouNums; j++)
			Byt[Data[j].Byte[i]]++;

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
	}	//�Ը����ķ���λ��Ϊ0����������λȡ��
}