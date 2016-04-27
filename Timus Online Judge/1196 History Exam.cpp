#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 15005;
int arr[MAXN],n,m;

bool bsearch(int x)
{
	int l=1,r=n,mid;
	while(l <= r)
	{
		mid = (l+r) >> 1;
		if(arr[mid] == x) return true;
		if(arr[mid] < x) l = mid+1;
		else r = mid-1;
	}
	return false;
}

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 1; i <= n; i ++) scanf("%d",&arr[i]);
		
		scanf("%d",&m);
		int ans = 0;
		while(m --)
		{
			int tmp;
			scanf("%d",&tmp);
			if(bsearch(tmp)) ans ++;
		}
		printf("%d\n",ans);
	}
}
