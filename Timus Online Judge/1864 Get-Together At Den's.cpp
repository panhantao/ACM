#include<iostream>
#include<cstdio>
#include<cstdlib>
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

double arr[105];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		double sum = 0;
		REP(i,1,n+1,1)
		{
			scanf("%lf",&arr[i]);
			sum += arr[i];
		}

		sum = sum/(n+1);

		REP(i,1,n+1,1) arr[i] -= sum;

		sum = 0;
		REP(i,1,n+1,1)
			if(arr[i] > 1e-7)
				sum += arr[i];

		REP(i,1,n+1,1)
		{
			if(arr[i] > 1e-7) printf("%d ",int(((100.0*arr[i])/sum)+1e-7));
			else printf("0 ");
		}
		printf("\n");
	}
}
