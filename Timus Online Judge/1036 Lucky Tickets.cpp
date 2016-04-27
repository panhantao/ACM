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

// dp[i][j] = sum(dp[i-1][j-k],k=0,1,2...,9 && j-k>=0)
string dp[55][505];

string Add(string a,string b)
{
	while(a.length() < b.length()) a.insert(0,1,'0');
	while(b.length() < a.length()) b.insert(0,1,'0');
	
	a.insert(0,1,'0'); b.insert(0,1,'0');
	
	for(int i = a.length()-1; i > 0; i --)
	{
		int tmp = a[i]-'0' + b[i]-'0';
		if(tmp > 9)
		{
			a[i-1] ++;
			a[i] = tmp%10 + '0';
		}
		else a[i] = tmp + '0';
	}
	while(a[0] == '0') a.erase(0,1);
	return a;
}

int arr[10005];
void Mul(string a,string b)
{
	if(a=="0" || b=="0")
	{
		ptf("0\n");
		return ;
	}
	MS(arr,0);
	reverse(a.begin(),a.end()); reverse(b.begin(),b.end());
	int p = a.length() + b.length();
	for(int i = 0; i < a.length(); i ++)
		for(int j = 0; j < b.length(); j ++)
		{
			arr[i+j] += (a[i]-'0') * (b[j]-'0');
			if(arr[i+j] > 9)
			{
				arr[i+j+1] += arr[i+j]/10;
				arr[i+j] %= 10; 
			}
		}
	while(arr[p] == 0) p --;
	for(int i = p; i >= 0; i --) ptf("%d",arr[i]);
	ptf("\n");
}

void init()
{
	for(int i = 0; i <= 500; i ++)
	{ 
		if(i < 10) dp[1][i] = "1";
		else dp[1][i] = "0";
	}
	
	for(int i = 2; i <= 50; i ++)
	{
		for(int j = 0; j <= 500; j ++) dp[i][j] = "0";
		for(int j = 0; j <= i*9; j ++)
			for(int k = 0; k <= 9 && j-k>=0; k ++)
				dp[i][j] = Add(dp[i][j],dp[i-1][j-k]);
	}
}

int main()
{
	init();
	
	int n,s;
	while(sf("%d%d",&n,&s) != EOF)
	{
		if(s&1)
		{
			ptf("0\n");
			continue;
		}
		s /= 2;
		Mul(dp[n][s],dp[n][s]);
	}
}
