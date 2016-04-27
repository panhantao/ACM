#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char str[55];
	while(scanf("%s",str) != EOF)
	{
		int len = strlen(str);
		int ans = 0;
		for(int i = 0; i < len; i ++)
			ans = (ans*10+str[i]-'0')%7;
		printf("%d\n",ans);
	}
}
