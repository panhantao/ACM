#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define ptf             printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define pf(x)           push_front(x)
#define mp              make_pair
#define MI(a,b)         a<b ? a:b
#define MX(a,b)         a<b ? b:a
#define LL              long long
#define PI              3.1415926535

struct Input
{
	int a,b;
	char sta[10];
}arr[5010];

const int diff = 15010;

int dsu[35000];
int n,m;

map<int,int> ma;
map<int,int>::iterator p;

int find(int x)
{
	if(x != dsu[x]) dsu[x] = find(dsu[x]);
	return dsu[x];
}

void Union(int a,int b)
{
	a = find(a); b = find(b);
	if(a != b) dsu[a] = b;
}

int main()
{
	while(sf("%d",&n) && n != -1)
	{
		ma.clear(); ma[0] = 0;
		for(int i = 0; i < 35000; i ++) dsu[i] = i;
		
		sf("%d",&m);
		for(int i = 0; i < m; i ++)
		{
			sf("%d %d %s",&arr[i].a,&arr[i].b,&arr[i].sta);
			ma[arr[i].a] = 0; ma[arr[i].a-1] = 0; ma[arr[i].b] = 0;
		}
		
		int z = 1;
		for(p = ma.begin(); p != ma.end(); p ++) p->second = z ++;
		
		int i;
		for(i = 0; i < m; i ++)
		{
			int x = ma[arr[i].a-1], y = ma[arr[i].b];
			
			if(arr[i].sta[0] == 'e')
			{
				if(find(x) == find(y+diff)) break;
				Union(x,y); Union(x+diff,y+diff);
			}
			else
			{
				if(find(x) == find(y)) break;
				Union(x,y+diff); Union(x+diff,y);
			}
		}
		ptf("%d\n",i);
	}
}
