/********************************************************
filename��		MySort.h
author��		Mako Wan
date��	2014-3-21
description��		ʵ�ֻ�������
********************************************************/
#ifndef MYSORT_H
#define MYSORT_H

union RadixData{

	double Dou;
	unsigned char Byte[sizeof(double)];

};

/*
��������	MySort
���ܣ�	��double�����л�������
���룺	����1�� double����	����2�� ����������
�����   ��
*/
void MySort(RadixData * DouBuf, int DouNums);
#endif