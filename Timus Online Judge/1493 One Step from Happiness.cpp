#include<iostream>
#include<cstdio>
#include<cstring>
#include<memory.h>
using namespace std;

bool check(char *str)
{
	int a = str[0]+str[1]+str[2];
	int b = str[3]+str[4]+str[5];
	return a == b;
}

int main()
{
	char str[10],a[10],b[10];
	int x;
	while(scanf("%s",str) != EOF)
	{
		memcpy(a,str,sizeof(str));
		x = 5; a[5] ++;
		while(a[x] > '9')
		{
			a[x] = '0';
			a[--x] ++;
		}
		
		memcpy(b,str,sizeof(str));
		x = 5; b[5] --;
		while(b[x] < '0')
		{
			b[x] = '9';
			b[--x] --;
		}
		
		if(check(a) || check(b)) printf("Yes\n");
		else printf("No\n");
	}
}
