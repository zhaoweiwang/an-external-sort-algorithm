/********************************************************
filename��		TempFileName.h
author��		Mako Wan
date��	2014-3-21
description��		�����ʱfilename�ַ���
********************************************************/
#ifndef TEMPFILENAME_H
#define TEMPFILENAME_H
/*
��������	TempFileName
���ܣ�	�����ʱfilename�ַ���
���룺	��ʱfilename��β��
�����   filename
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