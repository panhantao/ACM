#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n,temp,arr[100001];
	char ch[10];
	scanf("%d",&n);
	
	for(int i = 0; i < n; i ++)
		scanf("%d",&arr[i]);
		
	sort(arr,arr+n);
	//for(int i = 0; i < n;i ++)cout<<arr[i]<<" ";
	scanf("%s",&ch);
	
	scanf("%d",&n);
	
	for(int i = 0; i < n; i ++)
	{
		scanf("%d",&temp);
		printf("%d\n",arr[temp-1]);
	}
}
