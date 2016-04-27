#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const char name[] = "Sandro";

int main()
{
	char str[205];
	while(scanf("%s",str) != EOF)
	{
		int len = strlen(str);
		
		int ans = 20;
		for(int i = 0; i <= len-6; i ++)
		{
			int tmp = 0;
			
			if(isupper(str[i]))
			{
				if(str[i] != 'S') tmp ++;
			}
			else
			{
				if(toupper(str[i]) == 'S') tmp ++;
				else tmp += 2;
			}
			
			for(int j = 1; j < 6; j ++)
			{
				if(islower(str[i+j]))
				{
					if(str[i+j] != name[j]) tmp ++;
				}
				else
				{
					if(tolower(str[i+j]) == name[j]) tmp ++;
					else tmp += 2;
				}
			}
			if(tmp < ans) ans = tmp;
		}
		printf("%d\n",ans*5);
	}
}
