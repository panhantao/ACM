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
	int n,d1,d2;
	while(sf("%d%d%d",&n,&d1,&d2) != EOF)
	{
		int tot = n*d1;
		int per = ceil(1.0*tot/d2);
		
		REP(i,0,d2,1)
		{
			if(tot <= 0) printf("0 ");
			else if(tot >= per)
			{
				pf("%d ",per);
				tot -= per;
			}
			else
			{
				pf("%d ",tot);
				tot = 0;
			}
		}
		pf("\n");
	}
}
