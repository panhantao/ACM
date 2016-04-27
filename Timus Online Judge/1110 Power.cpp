#include<iostream>
#include<cstdio>
using namespace std;

int mod(int a,int b,int c)
{
	int ans = 1;
	for(int i = 0; i < b; i ++) ans = (ans*a)%c;
	return ans;
}

int main()
{
	int n,m,y;
	while(scanf("%d%d%d",&n,&m,&y) != EOF)
	{
		bool found = false;
		for(int i = 0; i < m; i ++)
			if(mod(i,n,m) == y)
			{
				printf("%d ",i);
				found = true;
			}
		if(!found) printf("%d\n",-1);
	}
}
