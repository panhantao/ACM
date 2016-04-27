#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<memory.h>
using namespace std;

int color[105],n,num=0;
vector<int> graph[105];
bool visited[105];

void bfs(int x)
{
	queue<int> que; que.push(x);
	visited[x] = true; color[x] = 1;
	
	while(!que.empty())
	{
		int now = que.front();
		que.pop();
		
		for(int i = 0; i < graph[now].size(); i ++)
		{
			int next = graph[now][i];
			if(!visited[next])
			{
				visited[next] = true;
				color[next] = -color[now];
				if(color[next] == -1) num ++;
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
	{
		int tmp;
		while(scanf("%d",&tmp) && tmp)
			graph[i].push_back(tmp);
	}
	
	memset(color,0,sizeof(color));	memset(visited,false,sizeof(visited));
	for(int i = 1; i <= n; i ++)
		if(!visited[i])
			bfs(i);
	
	printf("%d\n",num);
	for(int i = 1; i <= n; i ++)
		if(color[i] == -1)
			printf("%d ",i);
	printf("\n");
	//system("pause");
}
