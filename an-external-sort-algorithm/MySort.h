/********************************************************
�ļ�����		MySort.h
�����ˣ�		zhaoweiwang
��ע���ڣ�	2014-3-21
������		ʵ�ֻ�������
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