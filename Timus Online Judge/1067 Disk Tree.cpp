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

struct Trie
{
	Trie *next[53];
	bool end;
}node[40005];
int z;

map<char,int> m;
const char s[] = "\\!#$%&'()-0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZ^_`{}~";

void insert(char *str)
{
	Trie *root = &node[0];
	int len = strlen(str);

	for(int i = 0; i < len; i ++)
	{
		int pos = m[str[i]];
		if(root->next[pos] == NULL) root->next[pos] = &node[z ++];
		if(str[i] == '\\') root->end = true;
		root = root->next[pos];
	}
	root->end = true;
}

char word[100];
void dfs(const Trie *r,int idx)
{
	for(int i = 0; i < 53; i ++)
		if(r->next[i])
		{
			int len = strlen(word);
			word[len ++] = s[i];
			
			if(r->next[i]->end)
			{
				for(int i = 0; i < idx; i ++) pf(" ");
				
				int pos = len;
				while(word[pos] != '\\' && pos > 0) pos --;
				if(word[pos] == '\\') pos ++;
				
				for(int i = pos; i < len; i ++) pf("%c",word[i]); pf("\n");
			}
			
			if(s[i] == '\\') dfs(r->next[i],idx+1);
			else dfs(r->next[i],idx);
			
			word[--len] = 0;
		}
}

int main()
{
	//Fin("1.in"); Fout("1.out");
	for(int i = 0; i < 53; i ++) m[s[i]] = z ++;

	int n;
	while(sf("%d",&n) != EOF)
	{
		MS(node,0); z = 1;
		
		char str[100];
		for(int i = 0; i < n; i ++)
		{
			sf("%s",str);
			insert(str);
		}
		
		Trie *root = &node[0];
		dfs(root,0);
	}
}
