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

char str[300];
int mod3()
{
	int len = strlen(str);
	int ans = 0;
	for(int i = 0; i < len; i ++)
		ans = (ans*10 + str[i]-'0')%3;
	return ans;
}

int main()
{
	while(sf("%s",str) != EOF)
	{
		int k = mod3();
		if(k == 0) pf("2\n");
		else pf("1\n%d\n",k);
	}
}
