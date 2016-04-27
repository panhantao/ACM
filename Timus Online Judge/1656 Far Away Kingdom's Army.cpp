#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int tox[] = {0,1,0,-1};
const int toy[] = {1,0,-1,0};
int n,arr[100],ans[10][10];
bool v[100][100];

bool valid(int x,int y)
{
	if(v[x][y] || x < 0 || y < 0 || x >= n || y >= n) return false;
	return true;
}

void bfs(int x,int y)
{
	memset(v,false,sizeof(v));
	queue<int> qx,qy;
	qx.push(x); qy.push(y);
	v[x][y] = true;
	
	int iter = 0;
	ans[x][y] = arr[iter++];
	while(!qx.empty())
	{
		int nowx = qx.front(),nowy = qy.front();
		qx.pop(); qy.pop();
		for(int i = 0; i < 4; i ++)
		{
			int nextx = nowx+tox[i], nexty = nowy+toy[i];
			if(valid(nextx,nexty))
			{
				v[nextx][nexty] = true;
				qx.push(nextx); qy.push(nexty);
				ans[nextx][nexty] = arr[iter++];
			}
		}
	}
}

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < n*n; i ++) scanf("%d",&arr[i]);
		
		sort(arr,arr+n*n,greater<int>());
		
		bfs(n/2,n/2);
		
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < n; j ++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
}

