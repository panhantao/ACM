#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;

struct Edge
{
	int u,v,w;
}tmp;

bool cmp(const Edge &a,const Edge &b)
{
	return a.w < b.w;
}

vector<Edge> vec;
bool vis[250010],vvv[505];
int n,m,ans1,ans2;
int mst[505][505],f[505][505];

int dsu[505];
int find(int x)
{
	if(x != dsu[x]) dsu[x] = find(dsu[x]);
	return dsu[x];
}
void Union(int x,int y)
{
	x = find(x); y = find(y);
	dsu[x] = y;
}

int kruscal()
{
	sort(vec.begin(),vec.end(),cmp);
	for(int i = 0; i < 505; i ++) dsu[i] = i;
	memset(vis,false,sizeof(vis));
	memset(mst,-1,sizeof(mst));
	
	int ans = 0, cnt = 0;
	for(int i = 0; i < vec.size(); i ++)
	{
		int u = vec[i].u, v = vec[i].v, w = vec[i].w;
		if(find(u) == find(v)) continue;
		Union(u,v);
		ans += w;
		vis[i] = true;
		cnt ++;
		mst[u][v] = mst[v][u] = w;
	}
	if(cnt != n-1) return -1;
	return ans;
}

void bfs(int x)
{
	queue<int> que;
	que.push(x);
	memset(vvv,false,sizeof(vvv));
	vvv[x] = true;
	
	while(!que.empty())
	{
		int now = que.front();
		que.pop();
		
		for(int i = 1; i <= n; i ++)
		{
			if(!vvv[i] && mst[now][i]!=-1)
			{
				vvv[i] = true;
				f[x][i] = max(f[x][now],mst[now][i]);
				que.push(i);
			}
		}
	}
}

int secMST()
{
	if(ans1 == -1) return -1;
	
	memset(f,-1,sizeof(f));
	for(int i = 1; i <= n; i ++) bfs(i);
	
	int cnt = 0,ans = 0x1FFFFFFF;
	for(int i = 0; i < vec.size(); i ++)
		if(!vis[i])
		{
			int u = vec[i].u, v = vec[i].v, w = vec[i].w;
			ans = min(ans, ans1 + w - f[u][v]);
			cnt ++;
		}
	
	if(cnt == 0) return -1;
	else return ans;
}

int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		vec = vector<Edge>();
		
		for(int i = 0; i < m; i ++)
		{
			scanf("%d%d%d",&tmp.u,&tmp.v,&tmp.w);
			vec.push_back(tmp);
		}
		
		ans1 = kruscal();
		ans2 = secMST();
		
		printf("Cost: %d\n",ans1);
		printf("Cost: %d\n",ans2);
	}
}
