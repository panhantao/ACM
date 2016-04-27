#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int b,r,y;
	while(scanf("%d%d%d",&b,&r,&y) != EOF)
	{
		int k;
		scanf("%d",&k);
		
		int ans = 1;
		char str[10];
		for(int i = 0; i < k; i ++)
		{
			scanf("%s",str);
			if(str[0] == 'R') ans *= r;
			else if(str[0] == 'Y') ans *= y;
			else if(str[0] == 'B') ans *= b;
		}
		printf("%d\n",ans);
	}
}
