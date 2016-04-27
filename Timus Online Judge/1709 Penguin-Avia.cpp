#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

const int MAXN = 105;
int n,d,a;
char graph[MAXN][MAXN],res[MAXN][MAXN];
int block[MAXN],blocknum=0;
bool nv[MAXN],ev[MAXN][MAXN];
long long cost=0;

void dfs(int x)
{
	nv[x] = true;
	for(int i = 0; i < n; i ++)
	{
		if(graph[x][i] == '1')
		{
			if(ev[x][i] || ev[i][x]) continue;
			else
			{
				if(nv[i])
				{
					cost += d;
					res[x][i] = res[i][x] = 'd';
				}
				ev[x][i] = ev[i][x] = true;
				dfs(i);
			}
		}
	}
}

int main()
{
	scanf("%d\n%d %d",&n,&d,&a);

	for(int i = 0; i < n; i ++)
	{
		scanf("\n");
		for(int j = 0; j < n; j ++)
			scanf("%c",&graph[i][j]);
	}
	
	memset(res,'0',sizeof(res));
	memset(nv,false,sizeof(nv));
	memset(ev,false,sizeof(ev));
	
	for(int i = 0; i < n; i ++)
	{
		if(!nv[i])
		{
			dfs(i);
			block[blocknum ++] = i;
		}
	}
	
	for(int i = 1; i < blocknum; i ++)
	{
		res[block[0]][block[i]] = res[block[i]][block[0]] = 'a';
		cost += a;
	}
	printf("%lld\n",cost);
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < n; j ++)
			printf("%c",res[i][j]);
		printf("\n");
	}
	system("pause");
}
