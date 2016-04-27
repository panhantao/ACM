#include<iostream>
#include<cstdio>
#include<memory.h>
#include<stack>
using namespace std;

const int tox[] = {1,2,2,1,-1,-2,-2,-1};
const int toy[] = {2,1,-1,-2,-2,-1,1,2};
int n,n2;
bool v[10][10];
stack<int> stkx,stky;

bool valid(int x,int y)
{
	if(v[x][y] || x<0 || y<0 || x>=n || y>=n) return false;
	return true;
}

bool dfs(int x,int y)
{
	if(stkx.size() == n2) return true;
	
	for(int i = 0; i < 8; i ++)
	{
		int nx = x+tox[i];
		int ny = y+toy[i];
		
		if(valid(nx,ny))
		{
			stkx.push(nx);
			stky.push(ny);
			v[nx][ny] = true;
			if(dfs(nx,ny)) return true;
			v[nx][ny] = false;
			stky.pop();
			stkx.pop();
		}
	}
	return false;
}

bool solve()
{
	memset(v,false,sizeof(v));
	while(!stkx.empty()) { stkx.pop(); stky.pop(); }
			
	stkx.push(0); stky.push(0); v[0][0] = true;
	if(dfs(0,0)) return true;
}

void output()
{
	while(!stkx.empty())
	{
		printf("%c%d\n",stkx.top()+'a',stky.top()+1);
		stkx.pop(); stky.pop();
	}
}

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		if(n == 1) { printf("a1\n"); continue; }
		if(n == 2 || n == 3 || n == 4) { printf("IMPOSSIBLE\n"); continue; }
		
		n2 = n*n;
		
		solve();
		output();
	}
}
