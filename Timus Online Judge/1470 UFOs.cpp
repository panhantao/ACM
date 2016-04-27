#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

const int MAXN = 130; 

int c[MAXN][MAXN][MAXN];
int n;

int lowbit(int x)
{
	return x&(-x);
}

void update(int x,int y,int z,int val)
{
	for(int i = x; i <= n; i += lowbit(i))
		for(int j = y; j <= n; j += lowbit(j))
			for(int k = z; k <= n; k += lowbit(k))
				c[i][j][k] += val;
}

int sum(int x,int y,int z)
{
	int s = 0;
	for(int i = x; i > 0; i -= lowbit(i))
		for(int j = y; j > 0; j -= lowbit(j))
			for(int k = z; k > 0; k -= lowbit(k))
				s += c[i][j][k];
	return s;
}

void getsum(int x1,int y1,int z1,int x2,int y2,int z2)
{
	int s = 0;
	s += sum(x2,y2,z2); s -= sum(x1,y2,z2); s -= sum(x2,y1,z2);
	s -= sum(x2,y2,z1); s += sum(x2,y1,z1); s += sum(x1,y2,z1);
	s += sum(x1,y1,z2); s -= sum(x1,y1,z1);
	printf("%d\n",s);
}

int main()
{
	scanf("%d",&n);
	
	memset(c,0,sizeof(c));
	
	int m,x1,y1,z1,x2,y2,z2,k;
	while(scanf("%d",&m) && m != 3)
	{
		if(m == 1)
		{
			scanf("%d%d%d%d",&x1,&y1,&z1,&k);
			update(x1+1,y1+1,z1+1,k);
		}
		if(m == 2)
		{
			scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
			getsum(x1,y1,z1,x2+1,y2+1,z2+1);
		}
		if(m == 4)
		{
			for(int i = 0; i <= n; i ++)
				for(int j = 0; j <= n; j ++)
					for(int k = 0; k <= n; k ++)
						cout<<c[i][j][i]<<" ";
			cout<<endl;
		}
	}
}