/********************************************************
filename��		MemorySort.cpp
author��		Mako Wan
date��	2014-3-21
description��		���ų���Ķ�ȡ����ģ�飬ʵ�ֶ�ȡ���ݿ鹦�ܣ�
********************************************************/

#include "Head.h"
#include "MemorySort.h"
#include "Str2Dou.h"
#include "MySort.h"
#include "Dou2Str.h"
#include "OutPut.h"
#include <Windows.h>
#include <stdlib.h>

DWORD WINAPI MyThreadProc2(LPVOID lpParameter);
DWORD WINAPI MyThreadProc1(LPVOID lpParameter);


HANDLE hMutex;

int MyRead = 0;
FILE * InFile = NULL;			//���������ļ�ͷָ��
int FileCount = 0;				//���ݿ�������ͬʱҲ��K·�鲢��
char * OutFileName = NULL;

bool flag1 = false;
bool flag2 = false;

HANDLE MyHandle[2];


/*
��������	MemorySort
���ܣ�	��ȡfilename������ֿ�����
���룺	filename
�����   ���طָ��ļ�������
*/
int MemorySort(char * InFileName, char * OutFileNameTemp){


	OutFileName = OutFileNameTemp;

	InFile = fopen(InFileName, "r");
	if(InFile == NULL){
		cout << "����������������ļ�..." << endl;
		exit(1);
	}

	hMutex = CreateMutex(NULL, FALSE, NULL);

	MyHandle[0] = CreateThread(NULL, 0, MyThreadProc1, NULL, 0, NULL);
	MyHandle[1] = CreateThread(NULL, 0, MyThreadProc2, NULL, 0, NULL);
	
	WaitForMultipleObjects(2, MyHandle, FALSE, INFINITE);

	while(!(flag1 && flag2) == true){
		WaitForMultipleObjects(2, MyHandle, FALSE, INFINITE);
	}

	CloseHandle(MyHandle[0]);
	CloseHandle(MyHandle[1]);
	
	return FileCount;

}


DWORD WINAPI MyThreadProc1(LPVOID lpParameter)
{
	while(true)
	{

		WaitForSingleObject(hMutex,INFINITE);

		int			DouNums1;							//���ݿ鹲�ж��ٸ�������
		unsigned	int Length1 = 0;					//���ݿ�ĳ��ȣ����ֽ���
		char *		DataBuf1 = new char[DataBlock];		//���ݿ黺����
		double *	DouBuf1 = new double[MaxSizeDou];	//���ݿ�˫���ȸ���������
		char *		Buffer1 = new char[MyBufferSize];


		while(!(feof(InFile))){
			
				//�߳�1�Ķ���д
				if((Length1 = fread(DataBuf1, sizeof(char), DataBlock - 20, InFile)) < DataBlock - 20){

					ReleaseMutex(hMutex);

					DataBuf1[Length1] = '\0';

					DouNums1 = Str2Dou(DataBuf1, DouBuf1);

					MySort((RadixData*)DouBuf1, DouNums1);

					if(FileCount == 0){

						FILE * OutFile = NULL;
						OutFile = fopen(OutFileName, "wb");

						int LengthTemp, LengthOutPut = 0;
						for(int i = 0; i < DouNums1; i++){

							LengthTemp = Dou2Str(Buffer1 + LengthOutPut, DouBuf1[i]);
							LengthOutPut += LengthTemp;

						}
						fwrite(Buffer1, 1, LengthOutPut, OutFile);	//�������ַ���fwrite������ļ�

						fclose(OutFile);

						FileCount++;
					
					}
					else{

						char * FileName = TempFileName(FileCount++);

						FILE *TempFile = fopen(FileName, "wb");
						free(FileName);
						WriteData(TempFile, DouBuf1, DouNums1);

						fclose(TempFile);
					
					}

				}
				else{

					char * p = DataBuf1 + Length1 - 1;
					int i = 0;

					while(*p != '\n' && *p != '\0'){
						fread(DataBuf1 + Length1 + i, 1, 1, InFile);
						p++;
						i++;
					}
					DataBuf1[Length1 + i] = '\0';

					DouNums1 = Str2Dou(DataBuf1, DouBuf1);

					ReleaseMutex(hMutex);

					MySort((RadixData*)DouBuf1, DouNums1);

					char * FileName = TempFileName(FileCount++);

					FILE *TempFile = fopen(FileName, "wb");
					free(FileName);
					WriteData(TempFile, DouBuf1, DouNums1);

					fclose(TempFile);

				}
		}

		delete []DataBuf1;
		delete []DouBuf1;
		delete []Buffer1;
		break;

	}

	flag1 = true;
	return 0;

}



DWORD WINAPI MyThreadProc2(LPVOID lpParameter)
{
	while(true)
	{

		WaitForSingleObject(hMutex,INFINITE);

		int			DouNums2;							//���ݿ鹲�ж��ٸ�������
		unsigned	int Length2 = 0;					//���ݿ�ĳ��ȣ����ֽ���
		char *		DataBuf2 = new char[DataBlock];		//���ݿ黺����
		double *	DouBuf2 = new double[MaxSizeDou];	//���ݿ�˫���ȸ���������
		char *		Buffer2 = new char[MyBufferSize];
		

		while(!(feof(InFile))){		

				//�߳�1�Ķ���д
				if((Length2 = fread(DataBuf2, sizeof(char), DataBlock - 20, InFile)) < DataBlock - 20){

					ReleaseMutex(hMutex);

					DataBuf2[Length2] = '\0';

					DouNums2 = Str2Dou(DataBuf2, DouBuf2);

					MySort((RadixData*)DouBuf2, DouNums2);

					if(FileCount == 0){

						FILE * OutFile = NULL;
						OutFile = fopen(OutFileName, "wb");

						int LengthTemp, LengthOutPut = 0;
						for(int i = 0; i < DouNums2; i++){

							LengthTemp = Dou2Str(Buffer2 + LengthOutPut, DouBuf2[i]);							
							LengthOutPut += LengthTemp;

						}
						fwrite(Buffer2, 1, LengthOutPut, OutFile);

						fclose(OutFile);

						FileCount++;					
					
					}
					else{

						char * FileName = TempFileName(FileCount++);
						FILE *TempFile = fopen(FileName, "wb");
						free(FileName);
						WriteData(TempFile, DouBuf2, DouNums2);

						fclose(TempFile);
					
					}

				}
				else{

					char * p = DataBuf2 + Length2 - 1;
					int i = 0;

					while(*p != '\n' && *p != '\0'){
						fread(DataBuf2 + Length2 + i, 1, 1, InFile);
						p++;
						i++;
					}
					DataBuf2[Length2 + i] = '\0';

					DouNums2 = Str2Dou(DataBuf2, DouBuf2);

					ReleaseMutex(hMutex);

					MySort((RadixData*)DouBuf2, DouNums2);

					char * FileName = TempFileName(FileCount++);

					FILE *TempFile = fopen(FileName, "wb");
					free(FileName);
					WriteData(TempFile, DouBuf2, DouNums2);

					fclose(TempFile);

				}

		}

		delete []DataBuf2;
		delete []DouBuf2;
		delete []Buffer2;
		break;

	}

	flag2 = true;
	return 0;

}