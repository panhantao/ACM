#include<iostream>
#include<cstdio>
using namespace std;

int vote[10005] = {0};
int n,m,tmp;

int main()
{
	scanf("%d%d",&n,&m);
	
	for(int i = 0; i < m; i ++)
	{
		scanf("%d",&tmp);
		vote[tmp] ++;
	}
	
	for(int i = 1; i <= n; i ++)
		printf("%.2lf%%\n",vote[i]*100.0/m);
}
