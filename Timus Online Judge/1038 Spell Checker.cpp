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

int ans;
char ch;
bool insen,inword;

bool ismark(char ch)
{
	if(ch=='.' || ch=='?' || ch=='!') return true;
	return false;
}

int main()
{
	//Fin("1.in"); Fout("1.out");
	insen = inword = false;
	while(sf("%c",&ch) != EOF)
	{
		if(isalpha(ch))
		{
			if(!insen && islower(ch)) ans ++;
			if(inword && isupper(ch)) ans ++;
			insen = inword = true;
		}
		else if(ismark(ch)) insen = inword = false;
		else inword = false;
	}
	pf("%d\n",ans);
}
