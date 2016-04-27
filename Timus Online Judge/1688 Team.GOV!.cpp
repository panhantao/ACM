#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	long long n;
	int m,tmp;
	while(scanf("%lld%d",&n,&m) != EOF)
	{
		n *= 3;
		bool done = false;
		long long tot = 0;
		for(int i = 1; i <= m; i ++)
		{
			scanf("%d",&tmp);
			if(done) continue; 
			
			tot += tmp;
			
			if(tot > n)
			{
				printf("Free after %d times.\n",i);
				done = true;
			}
		}
		if(!done)
			printf("Team.GOV!");
	}
}
