#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int arr[100010];

void ini()
{
	arr[0] = 0;arr[1] = 1;
	for(int i = 2; i <= 100005; i ++)
	{
		if(i % 2 == 0)arr[i] = arr[i/2];
		else arr[i] = arr[i/2] + arr[i/2 + 1];
	}
}

int main()
{
	ini();
	int n;
	while(scanf("%d",&n) && n)
	{
		cout<<*max_element(arr,arr + n + 1)<<endl;
	}
	return 0;
}
