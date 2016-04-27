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
#define MI(a,b)			a<b ? a:b
#define MX(a,b)			a<b ? b:a

const int MAXN = 1000010;
int c[MAXN];
char opt[10];

int lowbit(int x) { return x&(-x); }

void update(int x,int val)
{
	for(int i = x; i <= MAXN; i += lowbit(i)) c[i] += val;
}

long long getsum(int x)
{
	long long s = 0;
	for(int i = x; i > 0; i -= lowbit(i)) s += c[i];
	return s;
}

int main()
{
	long long ans = 0,n = 0;
	MS(c,0);
	while(sf("%s",opt) && opt[0] != 'Q')
	{
		double x; int y;
		if(opt[0] == 'B')
		{
			sf("%lf",&x); x = x*100+0.1;
			update(int(x),1);
			n ++;
		}
		else if(opt[0] == 'D')
		{
			sf("%lf",&x); x = x*100+0.1;
			update(int(x),-1);
			n --;
		}
		else if(opt[0] == 'S')
		{
			sf("%lf%d",&x,&y); x = x*100+0.1;
			long long c = n - getsum(x-1);
			ans += MI(c,y);
		}
	}
	pf("%.2lf\n",ans*0.01);
}
