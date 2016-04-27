#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n;
	while(scanf("%d",&n) != EOF)
	{
		long long ans = 0;
		for(int i = 0; i <= n; i ++)
			for(int j = i; j <= n; j ++)
				ans += (i+j);
		printf("%lld\n",ans);
	}
}
