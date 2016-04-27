#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int d[2005],tmp;		// 0-init,1-obstacle,2-exit

int main()
{
	int n,x;
	while(scanf("%d%d",&n,&x) != EOF)
	{
		for(int i = 0; i < 2005; i ++) d[i] = 0;
		d[0] = d[2000] = 1;
		x += 1000;
		d[x] = 2;
		
		for(int i = 0; i < n; i ++)
		{
			scanf("%d",&tmp);
			tmp += 1000;
			d[tmp] = 1;
		}
		
		int la,lb;
		for(int i = x; i <= 2000; i ++)
			if(d[i] == 1)
			{
				la = i;
				break;
			}
		for(int i = x; i >= 0; i --)
			if(d[i] == 1)
			{
				lb = i;
				break;
			}
		// impossible
		if(lb > 1000 || la < 1000)
		{
			printf("Impossible\n");
			continue;
		}
		
		int ans=0;
		if(x > 1000)
		{
			printf("%d %d\n",x-1000,1000-lb+x-lb);
		}
		else
		{
			printf("%d %d\n",la-1000+la-x,1000-x);
		}
	}
}
