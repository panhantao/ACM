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
#define REP(i,o,b,d) 	for(int i = o; i < b; i += d)
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x);

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

double c[3005],s[30005];

int main()
{
	int n;
	double a0,an1;
	while(sf("%d",&n) != EOF)
	{
		sf("%lf%lf",&a0,&an1);
		
		s[0] = 0.0;
		REP(i,1,n+1,1)
		{
			sf("%lf",&c[i]);
			s[i] = s[i-1]+c[i];
		}
		
		double a1 = 1.0*n*a0+an1;
		
		REP(i,1,n+1,1) a1 -= 2*s[i];
		a1 /= (n+1);
		
		pf("%.2lf\n",a1);
	}
}
