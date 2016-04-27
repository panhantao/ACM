#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

#define MS(x,v) memset(x,v,sizeof(x))
#define REP(t,n) for(int t=0;t<n;t++)

const int MAXN = 100005;
int arr[MAXN],ans[MAXN];

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		MS(ans,0);
		
		int mx = -1,index;
		REP(i,n)
		{
			scanf("%d",&arr[i]);
			int tmp = i-arr[i]+1;
			if(tmp < 0) tmp += n;

			ans[tmp] ++;
			if(ans[tmp] > mx)
			{
				mx = ans[tmp];
				index = tmp+1;
			}
		}
		
		printf("%d\n",index);
	}
}
