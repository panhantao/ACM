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

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

const int tox[] = {1,0,-1,0};
const int toy[] = {0,-1,0,1};

string m[5],word;
bool v[5][5];

bool valid(int x,int y)
{
	if(x<0 || y<0 || x>3 || y>3 || v[x][y]) return false;
	return true;
}

bool found;
void dfs(int x,int y,int step)
{
	if(word[step] != m[x][y]) return ;
	if(step == word.length()-1)
	{
		found = true;
		return ;
	}
	
	v[x][y] = true;
	for(int i = 0; i < 4; i ++)
	{
		int nx = x+tox[i], ny = y+toy[i];
		if(valid(nx,ny)) dfs(nx,ny,step+1);
	}
	v[x][y] = false;
}

int main()
{
	for(int i = 0; i < 4; i ++) cin >> m[i];
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> word;
		
		found = false;
		for(int a = 0; a < 4; a ++)
			for(int b = 0; b < 4; b ++)
				dfs(a,b,0);
				
		if(found) cout<<word<<": YES"<<endl;
		else cout<<word<<": NO"<<endl;
	}
}
