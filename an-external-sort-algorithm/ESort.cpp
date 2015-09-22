/********************************************************
文件名：		ESort.cpp
创建人：		zhaoweiwang
加注日期：	2014-3-27
描述：		外排程序的主函数
********************************************************/

#include "Head.h"
#include "MemorySort.h"
#include "Merge.h"

int BadStrCount = 0;			//Invalid string in input counter.
string BadStr[1000];


int main(int argc, char * argv[]){

	char Str1[200];
	char Str2[200];
	char Temp[2];

	char * InFileName;
	char * OutFileNameTemp;

	FILE * InFile = fopen(argv[1], "rt");

	fscanf(InFile, "%[^\n]s", &Str1);
	int Str1Nums = strlen(Str1);
	for (int i = 0; i < Str1Nums; i++)
		if(Str1[i] == '\\')
			Str1[i] = '/';

	fscanf(InFile, "%c", &Temp);

	fscanf(InFile, "%[^\n]s", &Str2);
	int Str2Nums = strlen(Str2);
	for (int i = 0; i < Str2Nums; i++)
		if(Str2[i] == '\\')
			Str2[i] = '/';

	InFileName = new char[strlen(Str1) + 1];
	strcpy(InFileName, Str1);
	OutFileNameTemp = new char[strlen(Str2) + 1];
	strcpy(OutFileNameTemp, Str2);

	int FileNums = 0;	//File Number.

	LoserTree Ls;
	External b;

	//Starting The Game Clock.
	clock_t Start, Finish;
	double TotalTime;

	cout << "\n程序开始运行." << endl;
	cout << "已经打开" << InFileName << "文件" << endl;
	cout << "排序开始." << endl << endl;

	Start = clock();

	FileNums = MemorySort(InFileName, OutFileNameTemp);		//Read & sort & output`s module.

	cout << "\n文件块总数：" << FileNums <<  "块." <<  endl;


	if(FileNums == 0)
	{
		cout << "读取文件出错，可能是数据之间有多个分隔符" << endl;
	}
	else if(FileNums != 1)
	{
		Ls = new int[FileNums];
		b = new double[FileNums + 1];
		cout << "准备开始merge." << endl;
		Merge(b, FileNums, Ls, OutFileNameTemp);
		cout << "已经完成merge." << endl;

		delete []Ls;
		delete []b;
	}

	Finish = clock();
	TotalTime = (double)(Finish - Start) / CLOCKS_PER_SEC;
	cout << "\n总运行时间为:" << TotalTime << "秒.\n" << endl;

	if(BadStrCount){

		cout << "总共有非法字符串:" << BadStrCount << "个." << endl; 
		cout << "非法字符串：" << endl;
		for(int i = 0; i < BadStrCount; i++){

			cout << BadStr[i] << endl;

		}
		cout << "=====================" << endl;

	}
	else
		cout << "测试数据不含有非法字符串.\n=====================" << endl; 

	cin.get();

	return 0;

}