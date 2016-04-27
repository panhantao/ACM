#include<iostream>
#include<cstdio>
using namespace std;

const int Max = 32005;

int n;
int c[Max] = {0};
int level[Max] = {0};

int lowbit(int x)
{
	return x&(-x);
}

int sum(int i)
{
	int s = 0;
	while(i > 0)
	{
		s += c[i];
		i -= lowbit(i);
	}
	return s;
}

void update(int pos,int val)
{
	while(pos <= Max)
	{
		c[pos] += val;
		pos += lowbit(pos);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x ++;
		level[ sum(x) ] ++;
		update(x,1);
	}
	
	for(int i = 0; i < n; i ++)	printf("%d\n",level[i]);
}
