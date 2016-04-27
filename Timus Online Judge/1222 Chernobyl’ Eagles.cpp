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
#define LL				long long

string MUL(string x,int y)
{
	string ans = x;
	
	int c = 0;
	for(int i = 0; i < ans.length(); i ++)
	{
		int t = (ans[i]-'0')*y+c;

		ans[i] = t%10+'0';
		c = t/10;
	}
	while(c)
	{
		ans += c+'0';
		c /= 10;
	}
	return ans;
}

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		string ans = "1";
		
		if(n == 1) { pf("1\n"); continue; }
		
		if(n%3 == 1)
		{
			ans = MUL(ans,4);
			n -= 4;
		}
		else if(n%3 == 2)
		{
			ans = MUL(ans,2);
			n -= 2;
		}
		for(int i = 0; i < n/3; i ++)
			ans = MUL(ans,3);
		
		for(int i = ans.length()-1; i >= 0; i --) pf("%c",ans[i]);
		pf("\n");
	}
}
