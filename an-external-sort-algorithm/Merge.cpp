/********************************************************
文件名：		Merge.cpp
创建人：		zhaoweiwang
加注日期：	2014-3-21
描述：		K路归并算法
********************************************************/
#include "Head.h"
#include "Merge.h"

#include "OutPut.h"
#include "Dou2Str.h"


/*
函数名：	Adjust
功能：	调整败者树结构
输入：	参数1： s    参数2：K-way    参数3： 败者树    参数4：数组[K+1]
输出：   无
*/
void Adjust(int s, int FileNums, int *ls, double *b){
	int t = (s+FileNums)/2;
	while(t > 0){
		if(b[s] > b[ls[t]]){
			int temp = s;
			s = ls[t];
			ls[t] = temp;
		}
		t = t/2;
	}
	ls[0] = s;
}

/*
函数名：	CreateLoserTree
功能：	创建败者树
输入：	参数1： K-way    参数2：败者树    参数3： 数组[K+1] 
输出：   无
*/
void CreateLoserTree(int FileNums, int *ls, double *b){

	b[FileNums] = 2*MIN;

	for(int i = 0; i < FileNums; i++){
		ls[i] = FileNums;
	}

	for(int i = FileNums-1; i >= 0; i--){
		Adjust(i, FileNums, ls, b);
	}
}

char * Buffer1 = new char[MyBufferSizeTemp];
/*
函数名：	Merge
功能：	K路归并
输入：	参数1： 数组[K+1]    参数2：文件数    参数3： 败者树    参数4：输出文件名
输出：   无
*/
void Merge(double *b, int FileNums, int *ls, char * OutFileName){

	FILE *OutFile = fopen(OutFileName, "wb");
	FILE* *farray = new FILE *[FileNums];

	int i;

	for(i = 0; i < FileNums; i++){
		char* FileName = TempFileName(i);
		farray[i] = fopen(FileName, "rb");
		free(FileName);
	}

	for(i = 0; i < FileNums; i++){
		fread(b+i, sizeof(double), 1, farray[i]);
	}

	CreateLoserTree(FileNums, ls, b);

	int q;

	int j = 0;
	int len, length = 0;

	while(b[ls[0]] != MAX){
		q = ls[0];
		//cout << "double:" << b[q] << endl;
		len = Dou2Str(Buffer1 + length, b[q]);
		//len = FloatToStr(Buffer1 + length, b[q]);

		length += len;
		j++;
		if(j == SORT_NUM){
			//cout << "length: " << length << endl;
			fwrite(Buffer1, 1, length, OutFile);
			j = 0;
			length = 0;
		}

		if( fread(b+q, sizeof(double), 1, farray[q]) == 0)
			b[q] = MAX;
		Adjust(q, FileNums, ls, b);
	}

	if(j < SORT_NUM && j != 0){
		fwrite(Buffer1, 1, length, OutFile);
	}

	for(i = 0; i < FileNums; i++)
		fclose(farray[i]);

	delete []Buffer1;
	delete []farray;
	fclose(OutFile);

}