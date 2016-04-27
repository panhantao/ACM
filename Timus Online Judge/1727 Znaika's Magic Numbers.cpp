#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define REP(i,o,b,d) for(int i = o; i < b; i += d)
#define MS(x,val) memset(x,val,sizeof(x))
#define pb(x) push_back(x);
#define MX(a,b) a<b?b:a
#define MI(a,b) a<b?a:b

const int MAXN = 100005;
struct Node
{
	int val,num;
	friend bool operator<(const Node &a,const Node &b)
	{
		return a.val < b.val;
	}
}arr[MAXN];
bool v[MAXN];

int calc(int x)
{
	int ans = 0;
	while(x)
	{
		ans += x%10;
		x /= 10;
	}
	return ans;
}

void init()
{
	REP(i,0,100000,1)
	{
		arr[i].num = i;
		arr[i].val = calc(i);
	}
	sort(arr,arr+100000);
}

int main()
{
	init();
	int n;
	while(scanf("%d",&n) != EOF)
	{
		bool found = false;
		int ans[100000],z = 0;
		REP(i,1,100000,1)
		{
			int s = 0; z = 0;
			MS(v,false);
			REP(j,i,100000,1)
			{
				s += arr[j].val;
				ans[z++] = arr[j].num;
				if(s == n)
				{
					found = true;
					break;
				}
				else if(s > n) break;
			}
			if(found) break;
		}
		if(found)
		{
			printf("%d\n",z);
			REP(i,0,z,1) printf("%d ",ans[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
}