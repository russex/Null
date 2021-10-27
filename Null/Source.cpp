#include<iostream>
#include<Windows.h>
using namespace std;

void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);

void is_palindrome(char str[]);
int StringLength(char str[]);
void main()
{
	setlocale(LC_ALL, "");
	/*char str[] = "Hello";
	cout << str << endl;
	cout << str[1] << endl;
	cout << sizeof(str) << endl;*/
	const int n = 30;								// 3 способ
	char str[n] = {};
	cout << "Введите строку:";
	cin.getline(str, n);
	cout << str << endl;
	cout << StringLength(str) << endl;
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;
	cin.getline(str, n);
	is_palindrome(str);
	cout << str;

}
int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z') || (str[i] >= -32) && (str[i] <= -1))
		{
			str[i] -= 32;
		}
	}

}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z') || (str[i] >= -64) && (str[i] <= -33))
		{
			str[i] += 32;
		}
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] == 32) && (str[i + 1] == 32))
		{
			for (int j = i; str[j]; j++)
			{
					str[j] = str[j + 1];
			}
			i--;
		}
	}
}

void is_palindrome(char str[])
{
	int n = strlen(str)+1;
	char* strp = new char[n] {};
	for  (int i = 0; str[i]; i++)
	{
		strp[i] = str[i];
	}
	int it = 0; 
	for (int i = 0; str[i]; i++)
	{
		if(str[i]!=32)
		{
			it++;
		}
	}
	for (int i = 0; i<it; i++)
	{
		int buffer = strp[0];
		for (int j = 0; strp[j]; j++)
		{
			strp[j] = strp[j+1];
		}
		strp[it] = buffer;
	}
	cout << strp<<endl;
	
}
