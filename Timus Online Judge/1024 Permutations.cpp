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
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x);

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

int arr[2005];

int gcd(int a,int b)
{
	if(a < b) return gcd(b,a);
	if(a%b==0)return b;
	return gcd(b,a%b);
}

int lcm(int a,int b)
{
	int g = gcd(a,b);
	int ans = (a/g)*(b/g)*g;
	return ans;
}

int get(int x)
{
	int c = 1,tmp = x;
	while(x != arr[tmp])
	{
		c ++;
		tmp = arr[tmp];
	}
	return c;
}

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		for(int i = 1; i <= n; i ++) sf("%d",&arr[i]);
		
		int ans = get(1);
		for(int i = 2; i <= n; i ++)
		{
			int tmp = get(i);
			ans = lcm(ans,tmp);
		}
		pf("%d\n",ans);
	}
}
