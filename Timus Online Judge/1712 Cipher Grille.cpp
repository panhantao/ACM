#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
	int x,y;
	friend bool operator<(const Node &a,const Node &b)
	{
		if(a.x == b.x) return a.y < b.y;
		else return a.x < b.x;
	}
}node[5];

char map[5][5],tmp;

int main()
{
	int n = 0;
	for(int i = 1; i <= 4; i ++)
	{
		scanf("\n");
		for(int j = 1; j <= 4; j ++)
		{
			scanf("%c",&tmp);
			if(tmp == 'X')
			{
				node[n].x = i; node[n++].y = j;
			}
		}
	}
	
	for(int i = 1; i <= 4; i ++) scanf("%s",map[i]+1);

	for(int t = 0; t < 4; t ++)
	{
		sort(node,node+4);
		for(int i = 0; i < 4; i ++)
		{
			printf("%c",map[node[i].x][node[i].y]);
			swap(node[i].x,node[i].y);
			node[i].y = 5 - node[i].y;
		}
	}
	//system("pause");
}
