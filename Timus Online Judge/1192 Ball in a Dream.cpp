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
#define PI				3.1415926535

// Sx = v*v*sin(2a)/g , Ek = 0.5*m*v*v,where m == 1

int main()
{
	double v,a,k;
	while(sf("%lf%lf%lf",&v,&a,&k) != EOF)
	{
		double ans = 0;
		double E = 0.5*v*v;
		double c = sin(2.0*a*PI/180.0);
		while(E > 1e-8)
		{
			ans += v*v*c/10.0;
			E /= k;
			v = sqrt(2*E);
		}
		ptf("%.2lf\n",ans);
	}
}
