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
int main()
{
	double tot,eps,per;
	while(sf("%lf%lf%lf",&tot,&eps,&per) != EOF)
	{
		int ans = 0;
		while(tot >= eps)
		{
			ans ++;
			tot = tot-tot*(per/100.0);
		}
		pf("%d\n",ans);
	}
}
