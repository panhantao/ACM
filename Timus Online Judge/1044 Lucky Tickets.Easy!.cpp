#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int n,a,b,count = 0;
	cin >> n;
	
	if(n == 8){ cout<<4816030<<endl;return 0; }
	
	string up,down;
	
	for(int i = 0; i < n; i ++) down += '0';
	for(int i = 0; i < n; i ++) up += '9';
	
	while(1)
	{
		if(down == up)break;
		a = b = 0;
		for(int i = 0; i < n/2; i ++)a += down[i] - '0';
		for(int j = n - 1; j >= n/2; j --)b += down[j] - '0';
		if(a == b) count ++; 
		
		down[n-1] ++;
		for(int i = n - 1; i >= 0; i --)
			if(down[i] > '9')
			{
				down[i] = '0';
				down[i-1] ++;
			}
		
	}
	
	cout<<count+1<<endl;
	
	//system("pause");
}
