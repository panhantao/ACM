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

char var[5];
double val[5],R = 8.314,n,V,T,p;

int main()
{
	for(int i = 0; i < 2; i ++) sf("%c = %lf\n",&var[i],&val[i]);
	sf("%c = %lf",&var[2],&val[2]);
	
	n = V = T = p = -1.0;
	
	for(int i = 0; i < 3; i ++)
	{
		if(var[i] == 'p') p = val[i];
		if(var[i] == 'V') V = val[i];
		if(var[i] == 'n') n = val[i];
		if(var[i] == 'T') T = val[i];
	}
	
	// pV = nRT, Ideal Gas Equation
	if(p == -1)
	{
		pf("p = %.5lf\n",n*R*T/V);
	}
	else if(V == -1)
	{
		if(p == 0)
		{
			if(n != 0) pf("error\n");
			else pf("undefined\n");
		}
		else
		{
			double ans = n*R*T/p;
			if(ans == 0) pf("error\n");
			else pf("V = %.5lf\n",ans);
		}
	}
	else if(n == -1)
	{
		pf("n = %.5lf\n",p*V/(R*T));
	}
	else if(T == -1)
	{
		if(n == 0)
		{
			if(p == 0) pf("undefined\n");
			else pf("error\n");
		}
		else
		{
			double ans = p*V/(n*R);
			if(ans == 0) pf("error\n");
			else pf("T = %.5lf\n",ans);
		}
	}
}
