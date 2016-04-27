#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[2005];

int main()
{
	str[0] = '*';
	while(scanf("%s",str+1) != EOF)
	{
		int len = strlen(str);
		
		int i = 1, j = len-1;
		for(; i <= len/2; i ++, j--)
		{
			if(str[i] >= str[j]) str[j] = str[i];
			else
			{
				int k = j-1;
				while(str[k]=='9')
					str[k --] = '0';
				str[k] ++;
				str[j] = str[i];
			}
		}
		
		printf("%s\n",str+1);
	}
}
