#include<stdio.h>
int res[] = {1,1,2,0,2,1,2,0,1,1,2,0,1,1,2,0,1,1,2,0},n;

int main()
{
	scanf("%d",&n);
	printf("%d",res[((n%20)?n%20:20)-1]);
}
