/********************************************************
�ļ�����		Head.h
�����ˣ�		zhaoweiwang
��ע���ڣ�	2014-3-27
������		�������趫��
********************************************************/
#ifndef ESORT_H
#define ESORT_H


#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <tchar.h>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <time.h>


using namespace std;

#define MIN -1.79E+308
#define MAX 1.79E+308
#define DataBlock  145*1024*1024//150*1024*1024 //���ݿ��С
#define MaxSizeDou 10000000//5000000
#define MyBufferSize 200000001	
#define MyBufferSizeTemp 500000001


const int SORT_NUM = 25000000;

typedef int* LoserTree; //ls[t]���ڴ�Ű�������λ�ã�ls[0]������ʤ�ߵ�λ��
typedef double* External; //������Ҷ�ӽڵ��ֵ



//typedef char PathType[_MAX_PATH];	//·����

//extern char Buffer[MyBufferSize];

#endif