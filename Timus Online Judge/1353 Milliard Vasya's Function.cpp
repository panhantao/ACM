#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define pf 				printf
#define sf 				scanf
#define Fin(s)  		freopen(s,"r",stdin)
#define Fout(s) 		freopen(s,"w",stdout)
#define FIO(s)			Fin(s); Fout(s);
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x)
#define mp				make_pair

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

int dp[12][100];
// dp[i][j] = sigma(dp[i-1][j],dp[i-1][j-1],...,dp[i-1][j-9])

void init()
{
	dp[10][1] = 1;
	for(int i = 1; i <= 9; i ++) dp[1][i] = 1;
	
	for(int i = 2; i <= 9; i ++)
		for(int j = 1; j <= 81; j ++)
			for(int a = 0; a<=9 && j-a>=0; a ++)
				dp[i][j] += dp[i-1][j-a];
}

int main()
{
	init();
	int s;
	while(sf("%d",&s) != EOF)
	{
		int ans = 0;
		for(int i = 1; i <= 10; i ++) ans += dp[i][s];
		pf("%d\n",ans);
	}
}
