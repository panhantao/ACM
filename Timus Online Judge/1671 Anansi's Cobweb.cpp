#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

const int MAXN = 100005;

struct Edge
{
	int u,v;
	bool valid;
}edge[MAXN];

int n,m,q;
int s[MAXN];
int v[MAXN] = {false};
int query[MAXN];
int ans[MAXN];

int find(int x)
{
	if(s[x] < 0) return x;
	return s[x] = find(s[x]);
}

void Union(int x,int y)
{
	int root1 = find(x); int root2 = find(y);
	if(root1 == root2) return ;
	
	if(s[root1] < s[root2]) s[root2] = root1;
	else s[root1] = root2;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= m; i ++)
	{
		scanf("%d%d",&edge[i].u,&edge[i].v);
		edge[i].valid = true;
	}
	
	scanf("%d",&q);
	for(int i = 1; i <= q; i ++)
	{
		scanf("%d",&query[i]);
		edge[query[i]].valid = false;
	}
	
	// build joint set
	memset(s,0xff,sizeof(s));
	for(int i = 1; i <= m; i ++)
	{
		if(edge[i].valid)
			Union(edge[i].u,edge[i].v);
	}
	
	// find blocks
	int blocks = 0;
	for(int i = 1; i <= n; i ++)
	{
		int x = find(i);
		if(v[x] == false)
		{
			blocks ++;
			v[x] = true;
		}
	}
	
	// add edge
	for(int i = q; i >= 1; i --)
	{
		ans[i] = blocks;
		int x = find( edge[query[i]].u );
		int y = find( edge[query[i]].v );
		if(x != y) blocks --;
		Union(x,y);
	}
	
	// output answer
	for(int i = 1; i <= q; i ++)
		cout<<ans[i]<<" ";
	cout<<endl;
	
	//system("pause");
}