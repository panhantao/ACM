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

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b) != EOF)
	{
		int ans = MX(2*a+39,2*b+40);
		printf("%d\n",ans);
	}
}
