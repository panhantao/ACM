#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

const int MAXN = 3005;

struct Node
{
	int id;
	int l,r;
}node[MAXN];
int n,arr[MAXN],nodenum=0;

void insert(int x)
{
	if(node[0].id == -1) node[nodenum ++].id = x;
	else
	{
		int cur = 0,par = -1;
		while(cur != -1)
		{
			par = cur;
			if(x < node[cur].id)
			{
				cur = node[cur].l;
			}
			else
			{
				cur = node[cur].r;
			}
		}
		if(x < node[par].id)
			node[par].l = nodenum;
		else
			node[par].r = nodenum;
		node[nodenum ++].id = x;
	}
}

void traversal(int root)
{
	if(root == -1) return;
	traversal(node[root].r);
	traversal(node[root].l);
	printf("%d ",node[root].id);
}

int main()
{
	scanf("%d",&n); 
	for(int i = n; i >= 1; i --) scanf("%d",&arr[i]);
		
	memset(node,-1,sizeof(node));

	for(int i = 1; i <= n; i ++) insert(arr[i]);
	traversal(0);
	system("pause");
}
