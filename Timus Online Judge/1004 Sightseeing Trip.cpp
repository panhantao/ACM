#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

const int INF = 0x1FFFFFFF;
int n,m,graph[105][105],dist[105][105],fa[105][105],path[105],mincircle;

int main()
{
	while(scanf("%d",&n) && n != -1)
	{
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
			{
				graph[i][j] = dist[i][j] = INF;
				fa[i][j] = i;
			}
		
		scanf("%d",&m);
		for(int i = 0; i < m; i ++)
		{
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			graph[x][y]=graph[y][x]=dist[x][y]=dist[y][x]=min(graph[x][y],w);
		}
		
		// Floyd
		int p,num;
		mincircle = INF;
		for(int k = 1; k <= n; k ++)
		{
			for(int i = 1; i < k; i ++)
				for(int j = i+1; j < k; j ++)
				{
					int tmp = dist[i][j] + graph[i][k] + graph[k][j];
					if(tmp < mincircle)
					{
						mincircle = tmp;
						num = 0;
						p = j;
						while(p != i)
						{
							path[num ++] = p;
							p = fa[i][p];
						}
						path[num ++] = i;
						path[num ++] = k;
					}
				}
				
			for(int i = 1; i <= n; i ++)
				for(int j = 1; j <= n; j ++)
					if(dist[i][k]+dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k]+dist[k][j];
						fa[i][j] = fa[k][j];
					}
		}
		
		if(mincircle == INF) printf("No solution.\n");
		else
		{
			printf("%d",path[0]);
			for(int i = 1; i < num; i ++) printf(" %d",path[i]);
			printf("\n");
		}
	}
}
