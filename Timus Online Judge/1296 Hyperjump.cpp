#include<stdio.h>

int main()
{
	int i,n,temp,sum = 0,max = 0;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++)
	{
		scanf("%d",&temp);
		sum += temp;
				
		if(sum < 0)sum = 0;
		if(sum > max) max = sum;
	}
	printf("%d\n",max);
}
