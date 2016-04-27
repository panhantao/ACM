#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		int dp[20];
		dp[0] = 1; dp[1] = k-1;
		for(int i = 2; i <= n; i ++)
			dp[i] = (k-1)*(dp[i-1]+dp[i-2]);
		printf("%d\n",dp[n]);
	}
}
