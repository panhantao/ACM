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

char str[20005],ans[20005];

int z;
void dfs(int l,int r)
{
	if(l > r) return ;

	int mid = (l+r) >> 1;
	ans[mid] = str[z ++];
	
	if(l == r) return ;
	
	dfs(l,mid-1);
	dfs(mid+1,r);
}

int main()
{
	while(gets(str))
	{
		z = 0;
		int len = strlen(str);
		dfs(0,len-1);
		puts(ans);
	}
}                                 
