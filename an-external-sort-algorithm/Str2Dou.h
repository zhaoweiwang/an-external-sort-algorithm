/********************************************************
�ļ�����		Str2Dou.h
�����ˣ�		zhaoweiwang
��ע���ڣ�	2014-3-27
������		ʵ���ж��ַ���Ϊ�Ϸ��ַ�����������ת��Ϊdouble���ݣ�
********************************************************/
#ifndef STR2DOU_H
#define STR2DOU_H
/*
��������	Str2Dou
���ܣ�	�����ݿ��е��ַ���ת����double��
���룺	����1���ַ������ݿ�	����2��double���ݿ�
�����   ����double�����е�������
*/
int Str2Dou(char * DataBuf, double * DouBuf);
/*
��������	Str2DouPro
���ܣ�	�����ַ���ת������
���룺	����1���ַ���
�����   ����double��
*/
double Str2DouPro(const char * StrTemp);
#endif