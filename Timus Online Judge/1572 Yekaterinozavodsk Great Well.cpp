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

int main()
{
	double type,len;
	while(scanf("%lf%lf",&type,&len) != EOF)
	{
		if(type == 1) len *= 2.0;
		else if(type == 2) len *= 1.414213562;

		int n,ans = 0;
		scanf("%d",&n);
		REP(i,0,n,1)
		{
			double a,b;
			scanf("%lf%lf",&a,&b);
			if(a==1) b *= 2.0;
			else if(a==2) ;
			else b *= 0.866025404;

			if(b <= len) ans ++;
		}
		printf("%d\n",ans);
	}
}
