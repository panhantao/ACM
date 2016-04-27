#include<stdio.h>

int main()
{
	int count = 0;
	int a,b,i;
	scanf("%d%d",&a,&b);
	
	for(i = a; i <= b; i ++)
		if(i % 2 == 1)count ++;
		
	printf("%d\n",count);
}
