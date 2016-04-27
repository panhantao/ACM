#include<iostream>
#include<cstdio>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 33000;
vector<int> graph[MAXN];
bool visited[MAXN];
int route[MAXN],dist[MAXN],ans[MAXN];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		memset(visited,false,sizeof(visited));
		memset(dist,0,sizeof(dist));
		fill(graph,graph+MAXN,vector<int>());
		
		while(n --)
		{
			int k,tmp1,tmp2;
			scanf("%d",&k);
			scanf("%d",&tmp1);
			for(int i = 1; i < k; i ++)
			{
				scanf("%d",&tmp2);
				graph[tmp1].push_back(tmp2); graph[tmp2].push_back(tmp1);
				tmp1 = tmp2;
			}
		}
		scanf("%d",&n);
		for(int i = 0; i < n; i ++)  scanf("%d",&route[i]);
		
		queue<int> que;
		que.push(route[0]); visited[route[0]] = true; dist[0] = 0;
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
					dist[next] = dist[now] + 1;
					que.push(next);
				}
			}
		}
		
		memset(visited,false,sizeof(visited));
		for(int i = 0; i < n; i ++) visited[route[i]] = true;
		ans[0] = 1; ans[1] = route[n-1];
		que.push(route[n-1]);
		while(!que.empty())
		{
			int now = que.front();
			que.pop();
			for(int i = 0; i < graph[now].size(); i ++)
			{
				int next = graph[now][i];
				if(!visited[next] && dist[now]+1 == dist[next])
				{
					visited[next] = true;
					que.push(next);
					ans[++ans[0]] = next;
				}
			}
		}
		
		sort(ans+1,ans+1+ans[0]);
		for(int i = 1; i <= ans[0]; i ++) printf("%d\n",ans[i]);
	}
}
