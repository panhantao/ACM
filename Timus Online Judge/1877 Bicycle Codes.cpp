#include<stdio.h>

int main()
{
	int one,two;
	scanf("%d%d",&one,&two);
	
	if(one%2 == 0 || two%2 == 1) printf("yes\n");
	else printf("no\n");
}