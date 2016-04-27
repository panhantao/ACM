#include<iostream>
#include<cstdio>
using namespace std;

int arr[105][105],dp[105][105];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				scanf("%d",&arr[i][j]);
		
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				dp[i][j] = dp[i-1][j] + arr[i][j];
		
		int mx = -0x3FFFFFFF;

		for(int i = 1; i <= n; i ++)
			for(int j = i; j <= n; j ++)
			{
				int tmp = 0;
				for(int k = 1; k <= n; k ++)
				{
					tmp += dp[j][k]-dp[i-1][k];
					if(tmp > mx) mx = tmp;
					if(tmp < 0) tmp = 0; 
				}
			}
		printf("%d\n",mx);
	}
}
