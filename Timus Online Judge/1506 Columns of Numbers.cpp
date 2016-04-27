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

int ans[105][105];

int main()
{
	int n,k;
	while(sf("%d%d",&n,&k) != EOF)
	{
		int line;
		if(n%k == 0) line = n/k;
		else line = n/k+1;
		
		MS(ans,-1);
		int r=0,c=0;
		REP(i,0,n,1)
		{
			int tmp;
			sf("%d",&tmp);
			ans[r++][c] = tmp;
			if(r == line)
			{
				r = 0;
				c ++;
			}
		}
		
		REP(i,0,line,1)
		{
			REP(j,0,k,1)
			{
				if(ans[i][j] == -1) break;
				pf("%4d",ans[i][j]);
			}
			pf("\n");
		}
	}
}
