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

int n;
double x[13],y[13],r[13];
bool v[1005][1005];

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		MS(v,false);
		
		for(int i = 0; i < n; i ++)
			sf("%lf%lf%lf",&x[i],&y[i],&r[i]);
		
		int cnt = 0;
		for(double i = 0.000; i <= 1.000; i += 0.001)
			for(double j = 0.000; j <= 1.000; j += 0.001)
				for(int k = 0; k < n; k ++)
				{
					double d = (i-x[k])*(i-x[k]) + (j-y[k])*(j-y[k]);
					if(d <= r[k]*r[k])
					{
						if(!v[int(i*1000)][int(j*1000)]) cnt ++;
						v[int(i*1000)][int(j*1000)] = true;
					}
				}
		ptf("%.2lf\n",cnt*1.0/10000);
	}
}
