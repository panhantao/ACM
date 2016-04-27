#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string a,b;
	char cha,chb;
	int n;
	cin >> n;
	for(int i = 0; i < n;i ++)
	{
		cin >> cha >> chb;
		a += cha;
		b += chb;
	}

	for(int i = a.length()-1; i >= 0; i --)
	{
		int temp = a[i] - '0' + b[i] - '0';
		if(temp > 9)
		{
			a[i] = temp % 10 + '0';
			a[i-1] ++;
		}
		else
			a[i] = temp + '0';
	}
	
	cout<<a<<endl;
	//system("pause");
}
