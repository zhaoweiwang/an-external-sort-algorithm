/********************************************************
�ļ�����		TempFileName.h
�����ˣ�		zhaoweiwang
��ע���ڣ�	2014-3-21
������		�����ʱ�ļ����ַ���
********************************************************/
#ifndef TEMPFILENAME_H
#define TEMPFILENAME_H
/*
��������	TempFileName
���ܣ�	�����ʱ�ļ����ַ���
���룺	��ʱ�ļ�����β��
�����   �ļ���
*/
char * TempFileName(int Index);

/*
��������	WriteData
���ܣ�	�������TempFile�ļ���д������
���룺	����1�� �ļ�ָ��	����2�� �����ڴ��ַ	����3�� ��������
�����   ��
*/
void WriteData(FILE *TempFile, double *array, int n);

#endif