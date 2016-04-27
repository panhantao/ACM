#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n;
	char ch[30];
	cin >> n >> ch;
	
	long long sum = 1;
	int k = strlen(ch);
	long long rem = n;
	
	if(n % k != 0)
	{
		while(1)
		{
			sum *= rem;
			if(rem == n % k)break;
			else rem -= k;
		}
	}
	else
	{
		while(1)
		{
			sum *= rem;
			if(rem == k)break;
			else rem -= k;
		}
	}
	
	cout<<sum<<endl;
	//system("pause");
}
