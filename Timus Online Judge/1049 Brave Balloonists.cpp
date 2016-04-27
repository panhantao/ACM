#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i ++)
#define MS(arr,val) memset(arr,val,sizeof(arr))

bool isPrime[10005];
int prime[10000],p[10005];

void GetPrime()
{
	MS(isPrime,true);
	for(int i = 2; i*i < 10005; i ++)
		if(isPrime[i])
			for(int j = i; j*i < 10005; j ++)
				isPrime[i*j] = false;
	int n = 1;
	for(int i = 2; i < 10005; i ++)
		if(isPrime[i])
			prime[n++] = i;
}

int main()
{
	GetPrime();
	int tmp;
	REP(i,10)
	{
		scanf("%d",&tmp);
		int j = 1;
		while(tmp > 1)
		{
			if(tmp%prime[j] == 0)
			{
				p[prime[j]] ++;
				tmp /= prime[j];
			}
			else j ++;
		}
	}

	int ans = 1;
	REP(i,1000)
		if(p[i])
			ans *= (p[i]+1);
	printf("%d\n",ans%10);
}
