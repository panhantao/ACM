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

#define pf 				printf
#define sf 				scanf
#define Fin(s)  		freopen(s,"r",stdin)
#define Fout(s) 		freopen(s,"w",stdout)
#define FIO(s)			Fin(s); Fout(s);
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x)
#define mp				make_pair

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

struct Trie
{
	Trie *next[11];
	bool tail;
	int id;
}trie[100005];
int z;

const int m[] = {2,2,2,3,3,3,4,4,1,1,5,5,6,6,0,7,0,7,7,8,8,8,9,9,9,0};
char str[102],dict[50005][52],tmp[52];
int dp[102],len;
vector<int> ans[102];

void insert(const char *str,const int p)
{
	Trie *r = &trie[0];
	int len = strlen(str);
	for(int i = 0; i < len; i ++)
	{
		int idx = str[i]-'0';
		if(r->next[idx] == NULL)
			r->next[idx] = &trie[z++];
		r = r->next[idx];
	}
	r->tail = true; r->id = p;
}

void find(int sp)
{
	Trie *r = &trie[0];
	for(int i = sp; i < len; i ++)
	{
		int idx = str[i]-'0';
		if(r->next[idx] == NULL) return ;		// not match
		else r = r->next[idx];
		
		if(r->tail)			// reach dict tail
		{
			int dlen = strlen(dict[r->id]);		// dict length
			if(dp[i] == 0)
			{
				dp[i] = dp[i-dlen]+1;
				if(i-dlen >= 0) ans[i] = ans[i-dlen];	// the first matched word
				ans[i].pb(r->id);
			}
			else 
			{
				if(dp[i-dlen]+1 < dp[i])
				{
					dp[i] = dp[i-dlen]+1;
					ans[i] = ans[i-dlen];
					ans[i].pb(r->id);
				}
				else continue ;			// no need to search done
			}
			find(i+1);				// search recursively
		}
	}
}

int main()
{
	while(sf("%s",str) && str[0]!='-')
	{
		MS(trie,0); MS(dp,0); z = 1; fill(ans,ans+105,vector<int>());
		int n;
		sf("%d",&n);
		for(int i = 0; i < n; i ++)
		{
			sf("\n%s",dict[i]);
			len = strlen(dict[i]); 
			for(int j = 0; j < len; j ++)
				tmp[j] = m[dict[i][j]-'a']+'0';		// convert to digit
			tmp[len] = 0;
			insert(tmp,i);			// build Trie
		}

		len = strlen(str);
		find(0);				// begin searching

		if(dp[len-1] == 0) pf("No solution.\n");
		else
		{
			for(int i = 0; i < ans[len-1].size()-1; i ++)
				pf("%s ",dict[ans[len-1][i]]);
			pf("%s\n",dict[ans[len-1][ans[len-1].size()-1]]);
		}
	}
}
