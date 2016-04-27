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

int dp[10005];
bool cr[10005];

int main()
{
    double n,s;
    while(sf("%lf%lf",&n,&s) != EOF)
    {
		if(n == s)
		{
			ptf("1\n");
			continue;
		}
		
		MS(dp,0); MS(cr,false);
		
		cr[int(s)] = true;
		for(int i = s; i <= n; i ++)
		{
			if(!cr[i]) continue; 
			for(double p = 1.0; p <= 100.0; p ++)
			{
				double tmp = i*(1+p/100.0);
				int itmp = int(tmp);
				
				if(itmp > n) break;
				
				if(tmp-itmp < 1e-7)
				{
					dp[itmp] = MX(dp[i],dp[itmp])+1;
					cr[itmp] = true;
				}
			}
		}
		
		int mx = 0;
		for(int i = s; i <= n; i ++) mx = MX(mx,dp[i]);
		ptf("%d\n",mx+1);
	}
}
