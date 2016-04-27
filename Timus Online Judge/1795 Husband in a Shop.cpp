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

#define pf              printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define mp              make_pair
#define MI(a,b)			a<b ? a:b
#define MX(a,b)			a<b ? b:a

map<string,int> ma;
map<string,int>::iterator p;

int main()
{
	int n,m;
	while(sf("%d",&n) != EOF)
	{
		ma.clear();
		int val; string of,type;
		for(int i = 0; i < n; i ++)
		{
			cin >> val >> of >> type;
			ma[type] = val;
		}
		
		deque<string> tque;
		deque<int> vque,nque;
		sf("%d",&m);
		for(int i = 0; i < m; i ++)
		{
			cin >> val >> of >> type;
			tque.pb(type); vque.pb(val); nque.pb(-1);
		}
		
		int ans = 0;
		while(!tque.empty())
		{
			ans ++;
			string nowt = tque.front();
			int nowv = vque.front();
			int nown = nque.front();
			tque.pop_front();
			vque.pop_front();
			nque.pop_front();
			
			int have = ma[nowt];
			if(have == 0) continue;
			
			if(nowv <= have) ma[nowt] -= nowv;
			else
			{
				if(tque.empty()) break;
				if(nown == -1)
				{
					nown = have;
					swap(nowt,tque.front());
					swap(nowv,vque.front());
					swap(nown,nque.front());
					tque.push_front(nowt);
					vque.push_front(nowv);
					nque.push_front(nown);
				}
				else
				{
					if(nown == have) ma[nowt] = 0;
					else
					{
						nown = have;
						swap(nowt,tque.front());
						swap(nowv,vque.front());
						swap(nown,nque.front());
						tque.push_front(nowt);
						vque.push_front(nowv);
						nque.push_front(nown);
					}
				}
			}
		}
		pf("%d\n",ans);
	}
}
