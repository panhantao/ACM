#include<iostream>
#include<cstdio>
using namespace std;

int ans[100];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		ans[0] = 1;
		while(n != 1)
		{
			ans[ans[0]++] = n>>1;
			n = n-(n>>1);
		}
		printf("%d\n",ans[0]-1);
		for(int i = 1; i < ans[0]; i ++) printf("%d ",ans[i]);
		printf("\n");
	}
}
