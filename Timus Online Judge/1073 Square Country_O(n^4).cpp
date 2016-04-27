#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
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
#define Fout(s) 		freopen(s,"r",stdout)
#define REP(i,o,b,d) 	for(int i = o; i < b; i += d)
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x);

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

int sgn(int x)
{
	if(x > 0) return 1;
	else return 0;
}

int main()
{
	int n;
	sf("%d",&n);
	int x = int(sqrt(1.0*n));
	REP(a,0,x+1,1)
		REP(b,0,x+1,1)
			REP(c,0,x+1,1)
				REP(d,0,x+1,1)
					if(a*a + b*b + c*c + d*d == n)
					{
						printf("%d\n",sgn(a)+sgn(b)+sgn(c)+sgn(d));
						return 0;
					}
}
