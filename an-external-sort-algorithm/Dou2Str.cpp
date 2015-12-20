/********************************************************
filename��		Dou2Str.cpp
author��			Mako Wan
date��			2014-3-27
description��	ʵ�ֽ�������ת���ַ����Ĺ���
********************************************************/
#include "Head.h"
#include "Dou2Str.h"

/*
��������	DouResolve
���ܣ�	��˫���ȸ�����תΪʮ�����ַ���  
���룺	����1�� doubleָ��    ����2�� ����    ����3�� С��λ    ����4�� �ַ����ṹ��
�����   ��
*/
void DouResolve(PEXTENDED pvalue, FloatRec *rec)
{
	int power;
	double val;

	// 63λ��˫���ȸ���������λ
	rec->negative = *((LPBYTE)pvalue + 7) >> 7;      //1Ϊ����0Ϊ��

	// 52-62λ��˫���ȸ���������(���� - 0x3ff = ������ָ��)
	rec->exponent = (*(PUINT64)pvalue >> 52) & 0x7ff;

	if (!rec->exponent){  //*pvalue = 0
		rec->negative = 0;
		strcpy(rec->digits,"0000000000");
		return;
	}
	if (rec->exponent == 0x7ff){//*pvalue = nan or inf
		if ((*(PUINT64)pvalue & 0x000fffffffffffff) == 0){
			strcpy(rec->digits, "INF");
		} else{
			rec->exponent ++;
			rec->negative = 0;
			strcpy(rec->digits, "NAN");
		}
		return;
	}

	// ����ת��Ϊʮ����ָ��
	rec->exponent = DECIMAL_EXP(rec->exponent);

	// 0-51λ��˫���ȸ�����β��ת����F_MAXPRECISIONλʮ���Ƹ���������ʽ
	val = *pvalue;	
	*((LPBYTE)&val + 7) &= 0x7f;// val = fabs(*pvalue)

	int tmpexp=rec->exponent;
	double tmpval=val;
	if( tmpexp > 0){
		tmpval /= *(PEXTENDED)&_tab0[tmpexp & 31];
		tmpexp >>= 5;
		if(tmpexp)
			tmpval /=*(PEXTENDED)&_tab1[tmpexp - 1];
		while(tmpval < 1.0){
		
			rec->exponent--;
			tmpval*=10.0;

		}
		while(tmpval > 10.0){
		
			rec->exponent++;
			tmpval/=10.0;
		
		}
	}else if(tmpexp <0){
		tmpexp = -tmpexp;
		tmpval *= *(PEXTENDED)&_tab0[tmpexp & 31];
		tmpexp >>= 5;
		if(tmpexp)
			tmpval *=*(PEXTENDED)&_tab1[tmpexp - 1];
		if(tmpval < 1.0) {
			rec->exponent --;
			tmpval*=10.0;
		}
		while(tmpval>10.0){
		
			rec->exponent++;
			tmpval/=10.0;

		}
	}else {
		if(tmpval < 1.0){
			rec->exponent --;
			tmpval*=10.0;
		}
		while(tmpval>10.0){
		
			rec->exponent++;
			tmpval/=10.0;

		}
	}

	power = F_MAXPRECISION - rec->exponent;
	if (power > 0){ // if (power > 0) val *= (10**power)
		val *= *(PEXTENDED)&_tab0[power & 31]; 

		power >>= 5;            // power /= 32;
		if (power)
			val *= *(PEXTENDED)&_tab1[power - 1];
	}else if (power < 0){// if (power < 0) val /= (10**power)
		power = -power;
		val /= *(PEXTENDED)&_tab0[power & 31];
		power >>= 5;            // power /= 32;
		if (power)
			val /= *(PEXTENDED)&_tab1[power - 1];
	}


	// 9λʮ���Ƹ���������������
	
	val += 0.5;
	if (val >= _conPrec){
		val /= 10;
		rec->exponent ++; 
	}
	UINT64 value=(UINT64) val; 



	int i;

	for (i = 0; i <F_MAXPRECISION+1; i++){
		rec->digits[i] = (char)((value / _cvttab[i]) | 0x30);
		//cout << rec->digits[i] << " ";
		value %= _cvttab[i];
	}
	rec->digits[i]=0;
}

/*s
��������	Dou2Str
���ܣ�	��������ת�����ַ���
���룺	����1�� �ַ����ռ�    ����2�� ������
�����   ˫���ȸ������ַ�������
*/
int Dou2Str(char * StrBuf, double Num){

	FloatRec Rec;  
	char * pd = Rec.digits;  
	char * ps = StrBuf;  
	// ������������������Ϣ������rec  
	DouResolve(&Num, &Rec);  
	// ��ӡ��������  
	if(Rec.negative) *ps++ = '-';  
 
	if(*pd > '9')                 
	{  
		memcpy(ps, pd, 4);  
		return strlen(StrBuf);  
	}  

	*ps ++ = *pd ++;  

	if (*pd)  
		for (*ps ++ = '.'; *pd; *ps ++ = *pd ++);  


	// ת��Ϊָ����ʽ   
	int e, exp = Rec.exponent;  
	// ת��Ϊָ����ʽ   
	*ps ++ = 'E';  
	if(exp < 0){  
		exp = -exp;  
		*ps ++ = '-';  
	}  
	else *ps ++ = '+';  

	if((e = (exp / 1000)) != 0){  
		*ps ++ = e | 0x30;  
		exp %= 1000;  
	}  

	*ps ++ = (exp / 100) | 0x30;  
	exp %= 100;  

	*(unsigned short *)ps  = (((exp % 10) << 8) | (exp / 10)) | 0x3030; 

	ps +=2;
	* ps++= 0xA;
	* ps = 0; 

	return strlen(StrBuf);  
}