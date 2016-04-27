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
#define pf(x)           push_front(x)
#define mp              make_pair
#define MI(a,b)         a<b ? a:b
#define MX(a,b)         a<b ? b:a
#define LL              long long
#define PI              3.1415926535

const int MAXN = 100005;
int c[MAXN],n;

int lowbit(int x) { return x&(-x); }

void update(int pos,int val)
{
	for(int i = pos; i > 0; i -= lowbit(i)) c[i] += val;
}

int query(int pos)
{
	int s = 0;
	for(int i = pos; i <= n; i += lowbit(i)) s += c[i];
	return s;
}

int main()
{
	while(sf("%d",&n) != EOF)
	{
		MS(c,0);
		
		for(int i = 0; i <= n; i ++)
		{
			int a,b,c;
			sf("%d%d%d",&a,&b,&c);
			update(b,c);
			update(a-1,-c);
		}

		for(int i = 1; i < n; i ++)
			ptf("%d ",query(i));
		ptf("%d\n",query(n));
	}
}
