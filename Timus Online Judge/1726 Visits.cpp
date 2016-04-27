#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int x[100005], y[100005];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 1; i <= n; i ++) scanf("%d%d",&x[i],&y[i]);
		
		sort(x+1,x+1+n); sort(y+1,y+1+n);
		
		long long ans = 0;
		for(int i = 1; i < n; i ++)		// segment x[i+1]-x[i] will be passed i*(n-i)*2 times, so does y
		{
			//ans += (x[i+1]-x[i])*i*(n-i)*2 + (y[i+1]-y[i])*i*(n-i)*2;
			
			long long tmp = ( x[i+1]-x[i] + y[i+1]-y[i] );
			tmp *= i; tmp *= (n-i); tmp *= 2;
			ans += tmp;
		}
		
		ans /= n; ans /= (n-1);			// totally n*(n-1) routes
		
		printf("%lld\n",ans);
	}
}
