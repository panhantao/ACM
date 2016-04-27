#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
	int x,y,idx;
	friend bool operator<(const Node &a,const Node &b)
	{
		if(a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
}arr[10005];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < n; i ++)
		{
			scanf("%d%d",&arr[i].x,&arr[i].y);
			arr[i].idx = i+1;
		}
		
		sort(arr,arr+n);
	
		for(int i = 0; i < n; i += 2)
			printf("%d %d\n",arr[i].idx,arr[i+1].idx);
	}
}
