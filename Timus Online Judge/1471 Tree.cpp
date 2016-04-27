#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

const int MAXN = 50005;
vector<int> graph[MAXN],weight[MAXN];
int n,q;
int e[MAXN<<1],en=0,r[MAXN],rmq_min[MAXN<<1][25];
int dist[MAXN],level[MAXN<<1],l[MAXN];
bool visited[MAXN];

inline int min(const int &a,const int &b) { return a<b ? a:b;}

void dfs()			// non-recursive DFS
{
	memset(visited,false,sizeof(visited));
	memset(dist,-1,sizeof(dist));
	stack<int> sta; sta.push(0);
	visited[0] = true; level[0] = 0; dist[0] = 0;
	while(!sta.empty())
	{
		bool topop = true;
		int now = sta.top();
		e[en++] = now;
		for(int i = 0; i < graph[now].size(); i ++)
		{
			int next = graph[now][i];
			if(!visited[next])
			{
				topop = false;
				sta.push(next); visited[next] = true;
				l[next] = l[now]+1;
				if(dist[next] == -1)dist[next] = dist[now] + weight[now][i];
				break;
			}
		}
		if(topop) sta.pop();
	}
}

void init()
{
	// get r,level
	memset(r,-1,sizeof(r));
	for(int i = 0; i < en; i ++)
	{
		if(r[e[i]] == -1) r[e[i]] = i;
		level[i] = l[e[i]];
	}
	
	// rmq_min init
	for(int i = 0; i < en; i ++)
		rmq_min[i][0] = i;
	for(int f=1,s=1; s < en; s=(1<<f),f++)
		for(int i = 0; i+s < en; i ++)
		{
			int x=rmq_min[i][f-1],y=rmq_min[i+s][f-1];
			rmq_min[i][f] = level[x]<level[y] ? x:y;
		}
}

int rmq_query(int l,int r)
{
	if(l > r) swap(l,r);
	int d = r-l+1,k;
	for(k=0; (1<<k) <= d; k ++) ; k --;
	
	int x=rmq_min[l][k],y=rmq_min[r-(1<<k)+1][k];
	
	return level[x]<level[y] ? x:y;
}

int main()
{
	scanf("%d",&n);
	for(int i = 1; i < n; i ++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		graph[x].push_back(y); graph[y].push_back(x);
		weight[x].push_back(w); weight[y].push_back(w);
	}

	dfs();
	init();

	scanf("%d",&q);
	for(int i = 0; i < q; i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int lca = e[rmq_query(r[x],r[y])];

		printf("%d\n",dist[x]+dist[y]-2*dist[lca]);
	}
	
	//system("pause");
}
