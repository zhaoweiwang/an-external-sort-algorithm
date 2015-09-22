/********************************************************
文件名：		Head.h
创建人：		zhaoweiwang
加注日期：	2014-3-27
描述：		放置所需东西
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
#define DataBlock  145*1024*1024//150*1024*1024 //数据块大小
#define MaxSizeDou 10000000//5000000
#define MyBufferSize 200000001	
#define MyBufferSizeTemp 500000001


const int SORT_NUM = 25000000;

typedef int* LoserTree; //ls[t]用于存放败者树的位置，ls[0]存放最后胜者的位置
typedef double* External; //败者树叶子节点的值



//typedef char PathType[_MAX_PATH];	//路径名

//extern char Buffer[MyBufferSize];

#endif