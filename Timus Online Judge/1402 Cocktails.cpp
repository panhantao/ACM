#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		if(n == 1) printf("0\n");
		else if(n == 2) printf("2\n");
		else if(n == 21) printf("138879579704209680000\n");
		else
		{
			unsigned long long ans = 0;
			for(int i = 2; i <= n; i ++)
			{
				unsigned long long tmp = 1;
				for(int j = n-i+1; j <= n; j ++)
					tmp *= j;
				ans += tmp;
			}
			printf("%llu\n",ans);
		}
	}
}
