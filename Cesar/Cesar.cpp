#include "stdafx.h"
#include "Cesar.h"
#include <iostream>

using namespace std;

double f[26];
double frus[33];
double p[26] = {0.0817, 0.0149, 0.0278, 0.0425, 0.127, 0.0223, 0.0202, 0.0609, 0.0697, 0.0015, 0.0077, 0.0402, 0.0241, 
	0.0675, 0.0751, 0.0193, 0.0009, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0007};
char alf[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

CCesar::CCesar(void)
{

}

void CCesar::TransformToCesar(char buff[], unsigned int n)
{
	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++)
		{
			
			if((buff[i]>64)&&(buff[i]<91)||(buff[i]>96)&&(buff[i]<123)) 
						{
							//����������� ��� ��������� ����
							if(((buff[i]+n)>96)&&((buff[i]+n)<=122)) 
							{
								
								buff[i] = (buff[i]+n)%97+97;
							}
							else
							if ((buff[i]+n)>122) buff[i]= (buff[i]+n)%122 +96;
							else

							//����������� ��� ������� ����
							if(((buff[i]+n)>64)&&((buff[i]+n)<=90)) 
							{
								
								buff[i] = (buff[i]+n)%65+65;
							}
							else
							if (((buff[i]+n)>90)&&((buff[i]+n)<122)) buff[i]= (buff[i]+n)%90 +64;

							//����������� ��� ���� ����
							else	buff[i] += n;
						}
			else continue;
		}
		cout<<buff<<endl;
	}
	return;
}

void CCesar::TransformToCesarRus(char buff[], unsigned int n)
{
	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++)
		{
			
			if((buff[i]>='�')&&(buff[i]<='�')||(buff[i]>='�')&&(buff[i]<='�')) 
						{
							//����������� ��� ��������� ����

							if ((buff[i]>='�')&&((int)(buff[i]+n)>'�')) buff[i]= (buff[i]+n)%'�' +'�';
							else

							//����������� ��� ������� ����
							if(((buff[i]+n)>'�')&&((buff[i])<='�')) 
							{
								
								buff[i] = buff[i]%'�'+'�'+n-1;
							}

							//����������� ��� ���� ����
							else	 buff[i] += n;
						}
			else continue;
		}
		cout<<buff<<endl;
	}
	return;
}

void CCesar::DecodeFromCesar(char buff[], unsigned int n)
{
	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++)
		{
			if((buff[i]>64)&&(buff[i]<91)||(buff[i]>96)&&(buff[i]<123))
			{

				//������������� ��� ������� ����
							if((buff[i]-n)<65) 
							{
								
								buff[i] = 90-64%(buff[i]-n);
							}
							else

							//������������� ��� ��������� ����
							if(((buff[i]-n)>90)&&((buff[i]-n)<97)) 
							{
								//cout<<buff[i];
								buff[i] = 122-96%(buff[i]-n);
							}

							//����������� ��� ���� ����
							else	buff[i] -= n;


			}
			else continue;
		}
	
		cout<<buff<<endl;
	}
	return;
}

void CCesar::DecodeFromCesarRus(char buff[], unsigned int n)
{
	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++)
		{
			if((buff[i]>='�')&&(buff[i]<='�')||(buff[i]>='�')&&(buff[i]<='�')) 
			{

				//������������� ��� ��������� ����
							if(((buff[i]-n)<'�')&&(buff[i]>='�'))
							{
								
								buff[i] = '�'-'�'%(buff[i]);
							}
							else

							//������������� ��� ������� ����
							if(((buff[i]-n)<'�')&&(buff[i]>='�')) 
							{
								//cout<<buff[i];
								buff[i] = '�'-'�'%(buff[i]);
							}

							//����������� ��� ���� ����
							else	buff[i] -= n;


			}
			else continue;
		}
	
		cout<<buff<<endl;
	}
	return;
}


void CCesar::DecodeFromCesar(char buff[])
{
	char temp_buff[2024]={0};
	for(int i=0; i<26;i++)	f[i]=0;

	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++) 
		{

			temp_buff[i] = toupper(buff[i]);
			if(temp_buff[i]>'A'&&temp_buff[i]<'Z')
			f[temp_buff[i]-65]++;
			
		}

		double maxValue=0; int index=0;
		for(int i = 0;i < 26; i++) 
		{
			f[i]/=sizeof(buff);
			if (f[i]>maxValue) {maxValue=f[i]; index = i;}
		}
		
		unsigned int s = index+65-'E';// �����
		//cout<<"step "<<s<<endl;


		DecodeFromCesar(buff,s);

	}
	return;
}

void CCesar::DecodeFromCesarRus(char buff[])
{
	char temp_buff[2024]={0};
	for(int i=0; i<33;i++)	f[i]=0;

	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++) 
		{

			temp_buff[i] = toupper(buff[i]);
			if(temp_buff[i]>'�'&&temp_buff[i]<'�')
			f[temp_buff[i]-'�']++;
			
		}

		double maxValue=0; int index=0;
		for(int i = 0;i < 33; i++) 
		{
			f[i]/=sizeof(buff);
			if (f[i]>maxValue) {maxValue=f[i]; index = i;}
		}
		
		unsigned int s = index+'�'-'�';// �����
		//cout<<"step "<<s<<endl;


		DecodeFromCesarRus(buff,s);

	}
	return;
}


CCesar::~CCesar(void)
{
}
