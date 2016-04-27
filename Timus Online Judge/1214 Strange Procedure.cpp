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
#define Fout(s) 		freopen(s,"w",stdout)
#define REP(i,o,b,d) 	for(int i = o; i < b; i += d)
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x);

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

int main()
{
	long long a,b;
	while(sf("%lld%lld",&a,&b) != EOF)
	{
		if(a<=0 || b<=0) printf("%lld %lld\n",a,b);
		else if((a+b)%2 == 0) printf("%lld %lld\n",a,b);
		else printf("%lld %lld\n",b,a);
	}
}
