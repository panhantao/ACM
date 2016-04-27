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

map<string,int> ma;
map<string,int>::iterator miter;

set<string> un;
set<string>::iterator siter;

int opt[4][6] = {{2,4,1,3,0,5},
				 {4,2,0,3,1,5},
				 {0,1,5,2,3,4},
				 {0,1,3,4,5,2}};

vector<int> ans[100005];
int masize;

void bfs(string str,int idx)
{
	if(ma.find(str) != ma.end()) return ;
	
	un.clear();
	queue<string> que;
	que.push(str);
	
	while(!que.empty())
	{
		string now = que.front();
		que.pop();
		
		for(int i = 0; i < 4; i ++)
		{
			string nxt = "------";
			for(int j = 0; j < 6; j ++) nxt[j] = now[opt[i][j]];
			if(un.find(nxt) == un.end())
			{
				un.insert(nxt);
				que.push(nxt);
			}
		}
	}

	for(siter = un.begin(); siter != un.end(); siter ++)
		ma[*siter] = masize;
	masize ++;
}

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		ma.clear();
		vector<string> vec;
		masize = 0;
		
		for(int i = 0; i < n; i ++)
		{
			string s = "";
			for(int j = 0; j < 6; j ++)
			{
				char tmp;
				cin >> tmp;
				s += tmp;
			}
			
			vec.pb(s);
			bfs(s,i);
		}
		
		for(int i = 0; i < 100000; i ++) ans[i] = vector<int>();

		for(int i = 0; i < vec.size(); i ++)
		{
			int idx = ma.find(vec[i])->second;
			ans[idx].pb(i+1);
		}
		
		ptf("%d\n",masize);
		for(int i = 0; i < masize; i ++)
		{
			for(int j = 0; j < ans[i].size(); j ++)
				ptf("%d ",ans[i][j]);
			ptf("\n");
		}
	}
}
