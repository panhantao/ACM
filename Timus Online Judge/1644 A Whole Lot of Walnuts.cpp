#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int k[20],num,ans;			// 0-init,1-hungry,2-statisfied
char sta[10];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < 10; i ++) k[i] = 0;
		k[10] = 2; k[0] = k[1] = k[2] = 1;
		
		ans = 0;
		for(int i = 0; i < n; i ++)
		{
			scanf("%d %s",&num,sta);
			if(ans) continue;
			if(sta[0] == 'h')
			{
				int tmp = 1;
				for(int i = 2; i <= num; i ++)
				{
					if(k[i] && k[i]!=tmp) ans = 1;
					else k[i] = tmp;
				}
			}
			else if(sta[0] == 's')
			{
				int tmp = 2;
				for(int i = num; i <= 10; i ++)
				{
					if(k[i] && k[i]!=tmp) ans = 1;
					else k[i] = tmp;
				}
			}
		}
		if(ans == 0)
		{
			for(int i = 0; i <= 10; i ++)
				if(k[i] == 2)
				{
					printf("%d\n",i);
					break;
				}
		}
		else
			printf("Inconsistent\n");
	}
}
