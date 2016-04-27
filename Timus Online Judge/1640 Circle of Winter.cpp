#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

inline int dist(int x,int y)
{
	return x*x+y*y;
}

int main()
{
	int n,x,y;
	while(scanf("%d",&n) != EOF)
	{
		int mi = 0;
		for(int i = 0; i < n; i ++)
		{
			scanf("%d%d",&x,&y);
			if(dist(x,y) > mi)
				mi = dist(x,y);
		}
		double ans = sqrt(double(mi));
		printf("0 0 %.10lf\n",ans);
	}
}
