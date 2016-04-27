#include<iostream>
#include<cstdio>
using namespace std;

int n,seg[30005];		// seg[i] -> latest begin point that ends at i;
int dp[30005];

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < 30005; i ++) seg[i] = 0;
		
		int len = 0;
		while(n --)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			seg[r] = max(seg[r],l);
			
			len = max(len,r);
		}
		
		dp[0] = 0;
		
		for(int i = 1; i <= len; i ++)
		{
			if(seg[i] == 0) dp[i] = dp[i-1];
			else dp[i] = max(dp[i-1], dp[seg[i]-1]+1);
		}
		
		printf("%d\n",dp[len]);
	}
}
