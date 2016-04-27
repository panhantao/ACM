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
#define MI(a,b)			a<b ? a:b
#define MX(a,b)			a<b ? b:a
#define LL				long long

int main()
{
	int r;
	while(sf("%d",&r) != EOF)
	{
		int x = r;
		LL ans = 0;
		for(int y = 1; y <= r; y ++)
		{
			while((x-1)*(x-1)+(y-1)*(y-1) >= r*r) x --;	
			ans += x;
		}
		
		pf("%lld\n",ans<<2);
	}
}
