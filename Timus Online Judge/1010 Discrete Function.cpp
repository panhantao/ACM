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
#define pf(x)			push_front(x)
#define mp              make_pair
#define MI(a,b)			a<b ? a:b
#define MX(a,b)			a<b ? b:a
#define LL				long long

LL arr[100006];

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		for(int i = 0; i < n; i ++) sf("%lld",&arr[i]);
		
		LL ansa,ansb;
		LL mx = -1;
		for(int i = 1; i < n; i ++)
		{
			LL tmp = abs(arr[i]-arr[i-1]);
			if(tmp > mx)
			{
				mx = tmp;
				ansa = i;
				ansb = i+1;
			}
		}
		ptf("%lld %lld\n",ansa,ansb);
	}
}
