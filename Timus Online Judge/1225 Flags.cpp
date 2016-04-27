#include<stdio.h>

int main()
{
	int n,i;
	unsigned long long arr[50] = {0};
	arr[1] = arr[2] = 2;
	for(i = 3; i <= 45; i ++) arr[i] = arr[i-1] + arr[i-2];
	
	scanf("%d",&n);
	printf("%lld\n",arr[n]);
}
