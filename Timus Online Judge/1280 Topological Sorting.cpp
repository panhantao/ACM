#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> graph[1005];
int in[1005] = {0};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i = 0; i < m; i ++)
	{
		int s,u;
		scanf("%d%d",&s,&u);
		graph[s].push_back(u);
		in[u] ++;
	}
	
	for(int i = 0; i < n; i ++)
	{
		int v;
		scanf("%d",&v);
		if(in[v] == 0)
		{
			in[v] = -1;
			for(int j = 0; j < graph[v].size(); j ++)
				in[ graph[v][j] ] --;
		}
		else if(in[v] > 0)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	//system("pause");
}
