#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

int n,k;
int army[21][10005];
int c[10005];

int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int val)
{
	for(int i = x; i <= n; i += lowbit(i))
		c[i] += val;
}

int getsum(int x)
{
	int s = 0;
	for(int i = x; i > 0; i -= lowbit(i))
		s += c[i];
	return s;
}

int find_inversion(int x)
{
	memset(c,0,sizeof(c));
	
	int s = 0;
	for(int i = n; i >= 1; i --)
	{
		update(army[x][i]+1,1);
		s += getsum(army[x][i]);
	}
	return s;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 0; i < k; i ++)
		for(int j = 1; j <= n; j ++)
			scanf("%d",&army[i][j]);
		
	int maxstep = -1;
	int row;	
	for(int i = 0; i < k; i ++)
	{
		int tmp = find_inversion(i);
		if(tmp > maxstep)
		{
			maxstep = tmp;
			row = i+1;
		}
	}
	
	printf("%d\n",row);
	//system("pause");
}
