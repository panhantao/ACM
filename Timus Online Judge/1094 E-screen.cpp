#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define pf              printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define mp              make_pair
#define MI(a,b)			a<b ? a:b
#define MX(a,b)			a<b ? b:a

int main()
{
	char str[10005],ans[100];
	for(int i = 0; i < 100; i ++) ans[i] = ' ';
	gets(str);
	
	int ptr = 1,len = strlen(str);
	for(int i = 0; i < len; i ++)
	{
		if(str[i] == '<') ptr = MX(1,ptr-1);
		else if(str[i] == '>') ptr = ptr==80 ? 1:ptr+1;
		else
		{
			ans[ptr++] = str[i];
			if(ptr == 81) ptr = 1;
		}
	}
	for(int i = 1; i <= 80; i ++) pf("%c",ans[i]);
}
