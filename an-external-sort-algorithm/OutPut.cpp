/********************************************************
filename��		OutPut.cpp
author��		Mako Wan
date��	2014-3-27
description��		�����ʱfilename�ַ������������TempFile�ļ���д������
********************************************************/
#include "Head.h"
#include "OutPut.h"

/*
��������	TempFileName
���ܣ�	�����ʱfilename�ַ���
���룺	��ʱfilename��β��
�����   filename
*/
char * TempFileName(int Index){

	
	char* TempFile = new char[100];
	sprintf(TempFile, "TempFile%d", Index);
	return TempFile; // ������ʱfilename
}

/*
��������	WriteData
���ܣ�	�������TempFile�ļ���д������
���룺	����1�� �ļ�ָ��	����2�� �����ڴ��ַ	����3�� ��������
�����   filename
*/
void WriteData(FILE *TempFile, double *array, int n){

	int NumWrite = 0;
	NumWrite = fwrite(array, sizeof(double), n, TempFile);
}