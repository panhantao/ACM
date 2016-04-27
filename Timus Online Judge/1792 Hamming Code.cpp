#include<stdio.h>

int a[10],b[10],c1,c2,c3,i;

int check(int c1,int c2,int c3)
{
	if( (c1%2==b[5]) && (c2%2==b[6]) && (c3%2==b[7]) ) return 1;
	else return 0;
}

int main()
{
	for(i = 1; i <= 7; i ++) 
	{
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	
	if(check(a[2]+a[3]+a[4],a[1]+a[3]+a[4],a[1]+a[2]+a[4]))
	{
		;
	}
	else
	{
		for(i = 1; i <= 7; i ++) b[i] = a[i];
		
		for(i = 1; i <= 7; i ++)
		{
			if(a[i] == 0) b[i] = 1;
			else b[i] = 0;
			
			if( check(b[2]+b[3]+b[4],b[1]+b[3]+b[4],b[1]+b[2]+b[4]) ) break;
			else b[i] = a[i];
		}
	}
	
	for(i = 1; i <= 7; i ++) printf("%d ",b[i]);printf("\n");
}
