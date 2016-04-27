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
#define eps				1e-8
#define STOP			system("pause")

int m,n;
long long arr[105][505],dp[105][505];
int pre[105][505];

int main()
{
	while(~sf("%d%d",&m,&n))
	{
		for(int i = 1; i <= m; i ++)
			for(int j = 1; j <= n; j ++)
				sf("%lld",&arr[i][j]);
		
		for(int i = 1; i <= n; i ++) dp[1][i] = arr[1][i];
		for(int i = 2; i <= m; i ++)
		{
			for(int j = 1; j <= n; j ++) 
			{
				dp[i][j] = dp[i-1][j]+arr[i][j];	// from down
				pre[i][j] = j;
			}
			
			for(int j = 1; j <= n; j ++)
			{
				for(int k = j; k > 1; k --)			// to left
				{
					if(dp[i][k]+arr[i][k-1] < dp[i][k-1])
					{
						dp[i][k-1] = dp[i][k]+arr[i][k-1];
						pre[i][k-1] = k;
					}
					
				}
				
				for(int k = j; k < n; k ++)			// to right
				{
					if(dp[i][k]+arr[i][k+1] < dp[i][k+1])
					{
						dp[i][k+1] = dp[i][k]+arr[i][k+1];
						pre[i][k+1] = k;
					}
				}
			}
		}

		int mipos;
		long long mi = 1e18;
		for(int i = 1; i <= n; i ++)
		{
			if(dp[m][i] < mi)
			{
				mi = dp[m][i];
				mipos = i;
			}
		}
		
		int x = m,y = mipos;
		stack<int> stk;
		stk.push(mipos);
		while(pre[x][y])
		{
			stk.push(pre[x][y]);
			if(pre[x][y] == y)			// from down;
				x --;
			else if(pre[x][y] < y)		// from left
				y --;
			else 						// from right
				y ++;
		}
		
		ptf("%d",stk.top()); stk.pop();
		while(!stk.empty())
		{
			ptf(" %d",stk.top());
			stk.pop();
		}
		ptf("\n");
	}
}
