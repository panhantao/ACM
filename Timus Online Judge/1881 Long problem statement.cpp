#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int h,w,n;
	char str[105];
	while(scanf("%d%d%d",&h,&w,&n) != EOF)
	{
		int ans = 1,hh=h-1,ww=w;
		for(int i = 0; i < n; i ++)
		{
			scanf("%s",str);
			int len = strlen(str);
			
			if(len > ww)
			{
				ww = w-len;
				if(ww > 0) ww --;
				hh --;
				if(hh < 0)
				{
					hh = h-1;
					ans ++;
				}
			}
			else
			{
				ww = ww-len;
				if(ww > 0) ww --;
			}
			//printf("%d %d\n",hh,ww);
		}
		printf("%d\n",ans);
	}
}
