/********************************************************
�ļ�����		ESort.cpp
�����ˣ�		zhaoweiwang
��ע���ڣ�	2014-3-27
������		���ų����������
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

	cout << "\n����ʼ����." << endl;
	cout << "�Ѿ���" << InFileName << "�ļ�" << endl;
	cout << "����ʼ." << endl << endl;

	Start = clock();

	FileNums = MemorySort(InFileName, OutFileNameTemp);		//Read & sort & output`s module.

	cout << "\n�ļ���������" << FileNums <<  "��." <<  endl;


	if(FileNums == 0)
	{
		cout << "��ȡ�ļ���������������֮���ж���ָ���" << endl;
	}
	else if(FileNums != 1)
	{
		Ls = new int[FileNums];
		b = new double[FileNums + 1];
		cout << "׼����ʼmerge." << endl;
		Merge(b, FileNums, Ls, OutFileNameTemp);
		cout << "�Ѿ����merge." << endl;

		delete []Ls;
		delete []b;
	}

	Finish = clock();
	TotalTime = (double)(Finish - Start) / CLOCKS_PER_SEC;
	cout << "\n������ʱ��Ϊ:" << TotalTime << "��.\n" << endl;

	if(BadStrCount){

		cout << "�ܹ��зǷ��ַ���:" << BadStrCount << "��." << endl; 
		cout << "�Ƿ��ַ�����" << endl;
		for(int i = 0; i < BadStrCount; i++){

			cout << BadStr[i] << endl;

		}
		cout << "=====================" << endl;

	}
	else
		cout << "�������ݲ����зǷ��ַ���.\n=====================" << endl; 

	cin.get();

	return 0;

}