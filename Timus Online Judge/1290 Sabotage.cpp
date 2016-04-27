#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 25005;
int arr[MAXN];

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < n; i ++) scanf("%d",&arr[i]);
		
		sort(arr,arr+n,cmp);
		
		for(int i = 0; i < n; i ++) printf("%d\n",arr[i]);
	}
}
