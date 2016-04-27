#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int arr[1005];
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++) scanf("%d",&arr[i]);
	
	rotate(arr,arr+m%n,arr+n);

	for(int i = 0; i < 10; i ++)printf("%d",arr[i]);

}