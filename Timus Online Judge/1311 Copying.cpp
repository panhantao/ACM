#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		long long ans = 0,curline = 1,rem = n-1;
		while(curline<k && rem)
		{
			rem = max(rem-curline,0LL);
			if(curline*2 < k) curline <<= 1;
			else curline = k;
			ans ++;
		}
		if(rem == 0) ;
		else if(rem%k == 0) ans += rem/k;
		else ans += rem/k + 1;
		
		printf("%d\n",ans);
	}
}
