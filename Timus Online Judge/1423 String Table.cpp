#include<iostream>
#include<cstdio>
using namespace std;

char str[500010],pat[250005];
int _next[250005],n;

void getnext()
{
	int i = 0,j = -1; _next[0] = -1;
	while(i < n)
	{
		if(j==-1 || pat[i]==pat[j]) _next[++i] = ++j;
		else j = _next[j];
	}
}

int KMP()
{
	getnext();
	int i = 0,j = 0;
	while(i < n && j < 2*n)
	{
		if(i==-1 || pat[i]==str[j])
		{
			i ++;
			j ++;
		}
		else i = _next[i];
	}
	if(i >= n) return j-n;
	return -1;
}

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		memset(str,0,sizeof(str)); memset(pat,0,sizeof(pat));
		
		scanf("%s",str); scanf("%s",pat);
		for(int i = 0; i < n; i ++) str[i+n] = str[i];

		int ans = KMP();
		if(ans != -1) ans = n-ans;
		if(ans == n) ans = 0;
		printf("%d\n",ans);
	}
}
