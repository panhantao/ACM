#include<iostream>
#include<cstdio>
using namespace std;

int arr[20005];
long long sum[20005];

int main()
{
	int n,d;
	while(scanf("%d%d",&n,&d) != EOF)
	{
		for(int i = 1; i <= n; i ++)
		{
			scanf("%lld",&arr[i]);
			sum[i] = sum[i-1]+arr[i];
			if(sum[i] > i*d) sum[i] = i*d;
		}

		long long ans = 0,diff = 0;

		for(int i = n; i > 0; i --)
		{
			if(sum[i]-sum[i-1]+diff > d)
			{
				diff = sum[i]-sum[i-1]+diff-d;
				ans += diff;
			}
			else
				diff = 0;
		}

		printf("%lld %lld\n",sum[n],ans);
	}
}
