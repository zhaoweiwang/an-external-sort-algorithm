/********************************************************
�ļ�����		OutPut.cpp
�����ˣ�		zhaoweiwang
��ע���ڣ�	2014-3-27
������		�����ʱ�ļ����ַ������������TempFile�ļ���д������
********************************************************/
#include "Head.h"
#include "OutPut.h"

/*
��������	TempFileName
���ܣ�	�����ʱ�ļ����ַ���
���룺	��ʱ�ļ�����β��
�����   �ļ���
*/
char * TempFileName(int Index){

	
	char* TempFile = new char[100];
	sprintf(TempFile, "TempFile%d", Index);
	return TempFile; // ������ʱ�ļ���
}

/*
��������	WriteData
���ܣ�	�������TempFile�ļ���д������
���룺	����1�� �ļ�ָ��	����2�� �����ڴ��ַ	����3�� ��������
�����   �ļ���
*/
void WriteData(FILE *TempFile, double *array, int n){

	int NumWrite = 0;
	NumWrite = fwrite(array, sizeof(double), n, TempFile);
}