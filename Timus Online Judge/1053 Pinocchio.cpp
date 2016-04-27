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

int gcd(int a,int b)
{
	if(a < b) return gcd(b,a);
	if(a%b == 0) return b;
	return gcd(b,a%b);
}

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		int tmp,ans;
		for(int i = 0; i < n; i ++)
		{
			sf("%d",&tmp);
			if(i == 0) ans = tmp;
			else ans = gcd(ans,tmp);
		}
		pf("%d\n",ans);
	}
}
