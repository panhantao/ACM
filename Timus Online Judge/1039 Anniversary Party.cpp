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

#define ptf             printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define pf(x)           push_front(x)
#define mp              make_pair
#define MI(a,b)         a<b ? a:b
#define MX(a,b)         a<b ? b:a
#define LL              long long
#define PI              3.1415926535

int arr[6005],dp[6005][2];			// 0-not choose, 1-choose
vector<int> tree[6005];
bool isroot[6005];

void solve(int root)
{
	if(tree[root].size() == 0)		// leaf
	{
		dp[root][0] = 0;
		dp[root][1] = arr[root];
		return ;
	}
	
	for(int i = 0; i < tree[root].size(); i ++)
	{
		if(dp[tree[root][i]][0] == -1)
			solve(tree[root][i]);
	}
	
	// dp[root][0] = sum( max(dp[child][0], dp[child][1]) )
	// dp[root][1] = sum(dp[child][0]) + arr[root]
	
	dp[root][0] = 0;
	dp[root][1] = arr[root];
	for(int i = 0; i < tree[root].size(); i ++)
	{
		int child = tree[root][i];
		dp[root][0] += MX(dp[child][0],dp[child][1]);
		dp[root][1] += dp[child][0];
	}
}

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		MS(isroot,true);
		
		for(int i = 1; i <= n; i ++) sf("%d",&arr[i]);
		
		int l,k;
		while(sf("%d%d",&l,&k) && l)
		{
			tree[k].pb(l);
			isroot[l] = false;
		}
		
		int root;
		for(int i = 1; i <= n; i ++)
			if(isroot[i])
			{
				root = i;
				break;
			}
		
		MS(dp,-1);
		solve(root);
		
		ptf("%d\n",MX(dp[root][0],dp[root][1]));
	}
}
