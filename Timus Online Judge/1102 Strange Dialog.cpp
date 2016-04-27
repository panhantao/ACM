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
#include<list>
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
#define pause			system("pause")
#define PI              3.1415926535
#define eps				1e-8

char str[10000010];
bool dp[10000010];

bool check()
{
	MS(dp,false); dp[0] = true;
	int len = strlen(str);
	
	for(int i = 0; i < len; i ++)
	{
		if(!dp[i]) continue;
		
		if(str[i+1]=='i' && str[i+2]=='n')
		{
			dp[i+2] = true;
			if(str[i+3]=='p' && str[i+4]=='u' && str[i+5]=='t') dp[i+5] = true;
		}
		if(str[i+1]=='o')
		{
			if(str[i+2]=='n' && str[i+3]=='e') dp[i+3] = true;
			if(str[i+2]=='u' && str[i+3]=='t')
			{
				dp[i+3] = true;
				if(str[i+4]=='p' && str[i+5]=='u' && str[i+6]=='t') dp[i+6] = true;
			}
		}
		if(str[i+1]=='p' && str[i+2]=='u' && str[i+3]=='t' && str[i+4]=='o' && str[i+5]=='n') 
			dp[i+5] = true; 
	}
	return dp[len-1];
}

int main()
{
	int testcase;
	sf("%d",&testcase);
	while(testcase --)
	{
		sf("%s",str+1); str[0] = '*';
		
		if(check()) ptf("YES\n");
		else ptf("NO\n");
	}
}
