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

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		if(n == 1) pf("a\nb\nc\n");
		else
		{
			string str[] = {"abc","acb","bac","bca","cab","cba"};
			if(n <= 16666)
			{
				for(int i = 0; i < 6; i ++)
				{
					while(str[i].length() < n)
						str[i] += str[i];
					cout<<str[i].substr(0,n)<<endl;
				}
			}
			else pf("TOO LONG\n");
		}
	}
}
