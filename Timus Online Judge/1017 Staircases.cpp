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

#define pf              printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define mp              make_pair

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

long long dp[505][505];

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		MS(dp,0);
		dp[0][0] = 1;
		
		for(int i = 1; i <= n; i ++)
			for(int j = 0; j <= i; j ++)
				for(int k = 0; k < j; k ++)
					dp[i][j] += dp[i-j][k];
		
		long long q = 0;
		for(int i = 0; i < n; i ++) q += dp[n][i];
		
		pf("%lld\n",q);
	}
}                                 
