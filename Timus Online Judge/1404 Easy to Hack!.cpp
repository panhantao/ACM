#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	char str[105],ans[105]; 
	int s[105];
	while(scanf("%s",str) != EOF)
	{
		int len = strlen(str);
		for(int i = 0; i < len; i ++) s[i] = str[i]-'a';
		
		if(s[0] > 5) ans[0] = s[0]-5+'a';
		else ans[0] = 21+s[0]+'a';

		for(int i = 1; i < len; i ++)
		{
			ans[i] = (26+s[i]-s[i-1])%26;
			if(ans[i] < 0) ans[i] += 26;
			ans[i] += 'a';
			s[i] = s[i-1]+ans[i]-'a';
		}
		ans[len] = 0;
		printf("%s\n",ans);
	}
}
