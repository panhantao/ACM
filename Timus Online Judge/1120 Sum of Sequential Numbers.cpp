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

// 2N = 2AP+P^2-P = P(P+2A-1)
// A = (2N-P^2+P)/2P

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		n *= 2;
		for(int p = sqrt(1.0*n); p >= 1; p --)
		{
			if(n%p == 0)
			{
				int a = 1.0*(n-p*p+p)/(2.0*p);
				if(n%(p+2*a-1) == 0)
				{
					ptf("%d %d\n",a,p);
					break;
				}
			}
		}
	}
}
