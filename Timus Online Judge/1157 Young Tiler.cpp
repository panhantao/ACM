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

int m,n,k;

bool check(int l)
{
	int cn = 0;
	for(int i = 1; i <= sqrt(double(l)); i ++)
		if(l%i == 0)
			cn ++;
	
	if(cn != n) return false;
	
	l -= k;
	int cm = 0;
	for(int i = 1; i <= sqrt(double(l)); i ++)
		if(l%i == 0)
			cm ++;
	
	if(cm != m) return false;
	
	return true;
}

int main()
{
	while(sf("%d%d%d",&m,&n,&k) != EOF)
	{
		bool found = false;
		int l;
		for(l = k; l <= 10000; l ++)
		{
			if(check(l))
			{
				found = true;
				break;
			}
		}
		if(found) ptf("%d\n",l);
		else ptf("0\n");
	}
}
