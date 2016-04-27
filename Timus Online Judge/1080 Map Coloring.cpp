#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

const int MAXN = 105;

int n;
int color[MAXN];
vector<int> graph[MAXN];

bool bfs(int x)
{
	queue<int> que;
	que.push(x);
	color[x] = 0;
	
	while(!que.empty())
	{
		int now = que.front();
		que.pop();
		for(int i = 0; i < graph[now].size(); i ++)
		{
			int next = graph[now][i];
			if(color[next] == -1)
			{
				color[next] = (color[now] == 0) ? 1:0;
				que.push(next);
			}
			else if(color[next] == color[now]) return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
	{
		int tmp;
		while(scanf("%d",&tmp) && tmp)
		{
			graph[i].push_back(tmp);
			graph[tmp].push_back(i);
		}
	}
	
	memset(color,-1,sizeof(color));
	for(int i = 1; i <= n; i ++)
	{
		if(color[i] == -1)
		{
			if(bfs(i) == false)
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	for(int i = 1; i <= n; i ++) printf("%d",color[i]);
	//system("pause");
}
