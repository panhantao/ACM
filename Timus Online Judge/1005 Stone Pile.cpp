#include<iostream>
#include<cstdio>
#include<cmath> 
using namespace std;

int stone[21],dp[1000005];

int main()
{
	int n;
	scanf("%d",&n); 
	int sum = 0;			// 石子总和 
	for(int i = 0; i < n; i ++)
	{
		scanf("%d",&stone[i]);
		sum += stone[i];
	}
			
	int V = sum >> 1;		// 背包容量为石子总和的一半 
		
	// 0-1背包
	for(int i = 0; i < n; i ++)
		for(int j = V; j >= stone[i]; j --)
			dp[j] = max(dp[j], dp[j-stone[i]]+stone[i]);
		
	printf("%d\n",sum - 2*dp[V]);	// 最小差值 
}
