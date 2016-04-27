#include<iostream>
#include<cstdio>
#include<queue>
#include<memory.h>
using namespace std;

const int tox[] = {1,0,-1,0};
const int toy[] = {0,1,0,-1};

char map[40][40];
bool v[40][40];

int bfs(int x,int y)
{
	if(v[x][y]) return 0;
	
	queue<int> quex,quey;
	quex.push(x); quey.push(y);
	v[x][y] = true;
	int ans = 0;
	while(!quex.empty())
	{
		int nowx = quex.front(), nowy = quey.front();
		quex.pop(); quey.pop();
		for(int i = 0; i < 4; i ++)
		{
			int nextx = nowx + tox[i];
			int nexty = nowy + toy[i];
			if(!v[nextx][nexty] && map[nextx][nexty]=='.')
			{
				v[nextx][nexty] = true;
				quex.push(nextx); quey.push(nexty);
			}
			else if(map[nextx][nexty] == '#') ans ++;
		}
	}
	return ans;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		memset(map,'#',sizeof(map));
		
		for(int i = 1; i <= n; i ++)
		{
			scanf("\n");
			for(int j = 1; j <= n; j ++)
				scanf("%c",&map[i][j]);
		}
		
		map[0][1] = map[1][0] = map[n][n+1] = map[n+1][n] = '!';

		memset(v,false,sizeof(v));
		printf("%d\n",9*( bfs(1,1)+bfs(n,n) ));
	}
}
