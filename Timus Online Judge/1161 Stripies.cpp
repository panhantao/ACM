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

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		priority_queue<double,vector<double>,less<double> > que;
		double a,b;
		for(int i = 0; i < n; i ++)
		{
			sf("%lf",&a);
			que.push(a);
		}
		
		while(que.size() > 1)
		{
			a = que.top(); que.pop();
			b = que.top(); que.pop();
			que.push(2.0*sqrt(a*b));
		}
		
		pf("%.2lf\n",que.top());
	}
}
