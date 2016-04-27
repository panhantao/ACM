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
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x);

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

int arr[55];
bool dp[10005];

int main()
{
	int n,m;
	while(sf("%d%d",&n,&m) != EOF)
	{
		for(int i = 0; i < m; i ++) sf("%d",&arr[i]);
		
		dp[1] = false;
		for(int i = 2; i <= n; i ++)
		{
			dp[i] = false;
			for(int j = 0; j < m; j ++)
				if(i-arr[j]>0 && !dp[i-arr[j]])
					dp[i] = true;
		}

		if(dp[n]) pf("1\n");
		else pf("2\n");
	}
}
