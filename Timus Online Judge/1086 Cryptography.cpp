#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

bool prime[200000] = {0};
int arr[20000];

void ini()
{
	int index = 0;
	for(int i = 2; i * i <= 200000; i ++)
	{
		if(prime[i] == 0)
			for(int j = i; i * j <= 200000; j ++)
				prime[i*j] = 1;
	}
	
	for(int i = 1; i < 200000; i ++)
		if(prime[i] == 0)arr[index ++] = i;
}

int main()
{
	
	ini();
	
	int testcase;
	scanf("%d",&testcase);
	
	while(testcase --)
	{
		int n;
		scanf("%d",&n);
		
		printf("%d\n",arr[n]);
	}
}
