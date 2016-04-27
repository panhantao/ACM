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

int arr[2005],u[2005],d[2005],ans[2005][3];

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		MS(u,0); MS(d,0);
		for(int i = 1; i <= n; i ++) scanf("%d",&arr[i]);
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 1; j < i; j ++)
				if(arr[j] < arr[i]) d[arr[i]] ++;
			for(int j = i+1; j <= n; j ++)
				if(arr[j] > arr[i]) u[arr[i]] ++;
			ans[arr[i]][0] = i-d[arr[i]];
			ans[arr[i]][1] = i+u[arr[i]];
		}
		for(int i = 1; i <= n; i ++) pf("%d %d\n",ans[i][0],ans[i][1]);
	}
}
