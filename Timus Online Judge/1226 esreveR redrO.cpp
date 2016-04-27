#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	char ans[300],ch;
	int n = 0;
	while(1)
	{
		ch = getchar();
		if(ch == EOF) break;

		if(isalpha(ch)) ans[n ++] = ch;
		else
		{
			for(int i = n-1; i >= 0; i --) printf("%c",ans[i]);
			printf("%c",ch);
			n = 0;
		}
	}
	for(int i = n-1; i >= 0; i --) printf("%c",ans[i]);
}
