#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 10005;
int n,q,sum[MAXN];

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		sum[0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			scanf("%d",&sum[i]);
			sum[i] += sum[i-1];
		}
		
		scanf("%d",&q);
		while(q --)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",sum[y]-sum[x-1]);
		}
	}
}
