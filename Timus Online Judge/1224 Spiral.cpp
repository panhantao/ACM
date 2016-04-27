#include<iostream>
#include<cstdio>
using namespace std;

int n,m;

int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		if(n==2 || m==2) printf("2\n");
		else
		{
			long long sum;
			if(n <= m)
			{
				sum = n;
				sum += n-2;
			}
			else
			{
				sum = m;
				sum += m-1;
			}
			printf("%lld\n",sum);
		}
	}
}
