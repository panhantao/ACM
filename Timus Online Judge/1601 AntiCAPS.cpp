#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	char str[10010];
	bool cap = true;
	while(gets(str) != NULL)
	{
		int len = strlen(str);
		
		for(int i = 0; i < len; i ++)
		{
			if(cap && isalpha(str[i]))
				cap = false;
			else if(!cap && isalpha(str[i]))
			{
				str[i] = tolower(str[i]);
				cap = false;
			}
			else if(str[i]=='?' || str[i]=='.' || str[i]=='!')
				cap = true;
			printf("%c",str[i]);
		}
		printf("\n");
	}
}
