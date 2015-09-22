/********************************************************
�ļ�����		MemorySort.cpp
�����ˣ�		zhaoweiwang
��ע���ڣ�	2014-3-21
������		���ų���Ķ�ȡ����ģ�飬ʵ�ֶ�ȡ���ݿ鹦�ܣ�
********************************************************/

#include "Head.h"
#include "Str2Dou.h"

extern int BadStrCount; //�Ƿ��ַ���������
extern string BadStr[1000];

/*
��������	Str2DouPro
���ܣ�	�����ַ���ת������
���룺	����1���ַ���
�����   ����double��
*/
double Str2DouPro(char * StrTemp){
	long double DouFlag;
	long double DouValue = 0.L;
	int Sign = 0;	//����λ
	int Ex;	//ָ��λ

	int TenCount = 0; //��ʮλ������
	bool ZeroFlag = false;


	char * p = StrTemp;	//��ȡ�ַ����׵�ַ

	//���жϷ���
	if(*p == '+' || *p == '-'){
	
		Sign = *p;
		p++;
	}

	//ת�����ִ�
	while((int)(*p - '0') >= 0 && (int)(*p - '0') <= 9){

		if(ZeroFlag == false){
		
			if(*p != '0'){
				ZeroFlag = true;
				TenCount++;
			}

		}else{
		
			TenCount++;
			if(TenCount == 11)
				if(*p == '5')
					*p = '6';
		
		}

		DouValue = DouValue * 10 + (*p - '0');
		p++;
	}

	//ת��С���������ִ���������DouValue��
	if(*p == '.'){
		
		DouFlag = 1.L;
		p++;

		while((int)(*p - '0') >= 0 && (int)(*p - '0') <= 9){
		
			if(ZeroFlag == false){

				if(*p != '0'){
					ZeroFlag = true;
					TenCount++;
				}

			}else{

				TenCount++;
				if(TenCount == 11)
					if(*p == '5')
						*p = '6';
				//cout << *p << endl;

			}

			DouFlag *= 0.1;
			DouValue += (*p - '0')*DouFlag;
			p++;
			//cout << DouValue << endl;
		}
	}

	//�ж�ָ��λ
	if(*p == 'E' || *p == 'e'){
	
		DouFlag = 10.L;
		Ex = 0;
		p++;

		switch(*p){
		
		case '+':
			p++;
			break;
		case '-':
			DouFlag = 0.1;
			p++;
			break;
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case'9':
			break;
		default:
			DouFlag = 0.L;
			break;
		}

		while((int)(*p - '0') >= 0 && (int)(*p - '0') <= 9){
			
			Ex = Ex * 10 + (*p - '0');
			p++;
		}
		
		while(1){
		
			if(Ex & 1)
				DouValue *= DouFlag;
			Ex = Ex >> 1;
			if(Ex == 0)
				break;
			DouFlag *= DouFlag;
		}
	}
	
	return (Sign == '-' ? -DouValue : DouValue);
}

int judge(string str, int len){

	for(int i = 0; i < len; i++){
	
		if((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-' || str[i] == '.' || str[i] == 'E' || str[i] == 'e'){
			if(str[i] == '+' || str[i] == '-'){
				if(i == 0 || str[i - 1] == 'E' || str[i - 1] == 'e')
					continue;
				else
					return 0;
			}
			else if(str[i] == 'E' || str[i] == 'e'){
				if(i != 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
					continue;
				else
					return 0;
			}
			else if(str[i] == '.'){
				if(i != 0 && (str[i - 1] >= '0' && str[i - 1] <= '9') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
					continue;
				else
					return 0;
			}
			else
				continue;
		
		}
		else
			return 0;
	
	}

	return 1;

}

/*
��������	Str2Dou
���ܣ�	�����ݿ��е��ַ���ת����double��
���룺	����1���ַ������ݿ�	����2��double���ݿ�
�����   ����double�����е�������
*/
int Str2Dou(char *DataBuf, double *DouBuf){

	int DouNums = 0;
	int StrSize = 0;
	char *p = DataBuf;

	char StrTemp[25] = {0};

	while(*p != '\n' && *p != '\0'){
	
		StrTemp[StrSize] = *p;
		StrSize++;
		p++;

		if(*p == '\n'){

			p++;

			if(!(judge(StrTemp, StrSize))){
				
				BadStr[BadStrCount++] = StrTemp;
				
				for(int j = 0; j < StrSize; j++)
					StrTemp[j] = 0;

				StrSize = 0;
			
			}else{
			
				if(*p == '\0'){
					
					DouBuf[DouNums] = Str2DouPro(StrTemp);
					break;
				}

				DouBuf[DouNums] = Str2DouPro(StrTemp);

				for(int j = 0; j < StrSize; j++)
					StrTemp[j] = 0;

				StrSize = 0;
				DouNums++;
			}
		}
	}

	DouBuf[DouNums] = Str2DouPro(StrTemp);
	return DouNums+1;
}