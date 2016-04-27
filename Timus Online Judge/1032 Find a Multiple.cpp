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
#define pf(x)			push_front(x)
#define mp              make_pair
#define MI(a,b)			a<b ? a:b
#define MX(a,b)			a<b ? b:a
#define LL				long long

int arr[10005],sum[10005],pos[10005];

int main()
{
	int n;
	while(sf("%d",&n) != EOF)
	{
		sum[0] = 0;
		for(int i = 1; i <= n; i ++)
		{
			sf("%d",&arr[i]);
			sum[i] = (sum[i-1] + arr[i]) % n;
		}
		
		MS(pos,-1);
		
		for(int i = 0; i <= n; i ++)
		{
			if(pos[sum[i]] == -1) pos[sum[i]] = i;
			else
			{
				ptf("%d\n",i-pos[sum[i]]);
				for(int a = pos[sum[i]]+1; a <= i; a ++)
					ptf("%d\n",arr[a]);
				break;
			}
		}
	}
}
