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

#define pf 				printf
#define sf 				scanf
#define Fin(s)  		freopen(s,"r",stdin)
#define Fout(s) 		freopen(s,"w",stdout)
#define FIO(s)			Fin(s); Fout(s);
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x)
#define mp				make_pair

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

struct Node
{
	unsigned short sta,step;
}ori,now,nxt;

bool v[70000];
unsigned int flag[] = {19,39,78,140,
						305,626,1252,2248,
						4880,10016,20032,35968,
						12544,29184,58368,51200};

int bfs()
{
	MS(v,false); v[ori.sta] = true;
	queue<Node> que; que.push(ori);

	while(!que.empty())
	{
		now = que.front(); que.pop();
		if(now.sta == 0 || now.sta == 65535) return now.step;
		
		for(int i = 0; i < 16; i ++)
		{
			nxt = now;
			nxt.sta ^= flag[i];
			if(!v[nxt.sta])
			{
				v[nxt.sta] = true;
				nxt.step = now.step + 1;
				que.push(nxt);
			}
		}
	}
	return -1;
}

int main()
{
	ori.sta = ori.step = 0;
	char str[10];
	int two = 1;
	for(int i = 0; i < 4; i ++)
	{
		sf("%s",str);
		for(int j = 0; j < 4; j ++)
		{
			if(str[j] == 'b') ori.sta += two;
			two <<= 1;
		}
	}
	
	int ans = bfs();
	if(ans == -1) pf("Impossible\n");
	else pf("%d\n",ans);
}
