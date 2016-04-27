#include<iostream>
#include<cstdio>
using namespace std;

long long list[10005];

int main()
{
	long long fd = 9,sd = 9;
	list[1] = 3;
	for(int i = 2; i <= 10000; i ++)
	{
		list[i] = list[i-1]+fd;
		fd += sd;
		sd += 3;
	}
	
	int n;
	while(scanf("%d",&n) != EOF)
	{
		printf("%lld\n",list[n]);
	}
}
