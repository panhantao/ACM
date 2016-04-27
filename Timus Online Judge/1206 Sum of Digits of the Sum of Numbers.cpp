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

string mul(string x)
{
	string res;
	for(int i = 0; i < x.length(); i ++) res.insert(0,1,x[i]);
	x = res;
	int c = 0;
	
	for(int i = 0; i < x.length(); i ++)
	{
		int tmp = 5*(x[i]-'0')+c;
		c = tmp/10;
		x[i] = tmp%10+'0';
	}
	if(c > 0) x += c+'0';
	
	string x2 = x;
	x2.insert(0,1,'0'); x += '0';
	
	res = ""; c = 0;
	for(int i = 0; i < x.length(); i ++)
	{
		int tmp = (x[i]-'0'+x2[i]-'0')+c;
		c = tmp/10;
		res += tmp%10+'0';
	}
	if(c > 0) res += c+'0';
	for(int i = 0; i < res.length()/2; i ++) swap(res[i],res[res.length()-1-i]);
	return res;
}

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		//	ans = 36*55^(n-1)
		string ans = "36";
		for(int i = 0; i < n-1; i ++) ans = mul(ans);
		cout<<ans<<endl;
	}
}
