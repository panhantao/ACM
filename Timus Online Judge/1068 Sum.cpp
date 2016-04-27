#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
	int a;
	int sum = 0;
	cin >> a;
	if (a < 1)
		for(int i = a; i <= 1; i ++)sum += i;
	else
		for(int i = 1; i <= a; i ++)sum += i;
		
	cout<<sum<<endl;
	//system("pause");
}
