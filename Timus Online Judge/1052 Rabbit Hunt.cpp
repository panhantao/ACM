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

#define REP(i,o,b,d) for(int i = o; i < b; i += d)
#define MS(x,val) memset(x,val,sizeof(x))
#define pb(x) push_back(x);
#define MX(a,b) a<b?b:a
#define MI(a,b) a<b?a:b

double x[205],y[205];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		REP(i,0,n,1) scanf("%lf%lf",&x[i],&y[i]);

		int ans=0;
		REP(i,0,n,1)
			REP(j,i+1,n,1)
			{
				int tmp = 0;
				if(fabs(x[i]-x[j]) < 1e-7)
				{
					REP(a,0,n,1)
						if(fabs(x[a]-x[i]) < 1e-7)
							tmp ++;
				}
				else
				{
					double k = (y[i]-y[j])/(x[i]-x[j]);
					double b = y[i]-k*x[i];
					REP(a,0,n,1)
						if(fabs(y[a]-k*x[a]-b) < 1e-7)
							tmp ++;
				}
				ans = MX(ans,tmp);
			}
		printf("%d\n",ans);
	}
}
