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

int gcd(int a,int b)	
{
	if(a < b) return gcd(b,a);
	if(a%b == 0) return b;
	return gcd(b,a%b);
}

int main()
{
	int x,y;
	while(sf("%d%d",&x,&y) != EOF)
	{
		x --; y --;
		ptf("%d\n",x+y-gcd(x,y));
	}
}
