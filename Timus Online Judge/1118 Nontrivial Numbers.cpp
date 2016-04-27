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

bool isPrime[1000005];

void init()
{
	MS(isPrime,true);
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i*i <= 1000005; i ++)
		if(isPrime[i])
			for(int j = i; j*i <= 1000005; j ++)
				isPrime[i*j] = false;
}

bool check(int x,int y)
{
	for(int i = y; i >= x; i --)
		if(isPrime[i])
		{
			pf("%d\n",i);
			return true;
		}
	return false;
}

double calc(int x)
{
	double tmp = 0;
	for(int i = 1; i < x; i ++)
		if(x%i == 0)
			tmp += 1.0*i/x;
	return tmp;
}

int main()
{
	init();
	int i,j;
	while(sf("%d%d",&i,&j) != EOF)
	{
		if(i == 1) pf("1\n");
		else if(!check(i,j))
		{
			double miv=1000; int mii;
			for(int a = i; a <= j; a ++)
			{
				double tmp = calc(a);
				if(tmp < miv)
				{
					miv = tmp;
					mii = a;
				}
			}
			pf("%d\n",mii);
		}
	}
}                                 
