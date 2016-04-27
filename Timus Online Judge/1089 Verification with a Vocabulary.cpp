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

#define ptf             printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define pf(x)           push_front(x)
#define mp              make_pair
#define MI(a,b)         a<b ? a:b
#define MX(a,b)         a<b ? b:a
#define LL              long long
#define PI              3.1415926535

vector<string> dict[100];

int cmp(string a,string b)
{
	int ans = 0;
	for(int i = 0; i < a.length(); i ++)
		if(a[i] != b[i])
			ans ++;
	return ans;
}

int output(string str)
{
	int len = str.length();
	
	bool change = false;
	for(int i = 0; i < dict[len].size(); i ++)
	{
		if(cmp(str,dict[len][i]) == 1)
		{
			change = true;
			str = dict[len][i];
			break;
		}
	}
	cout<<str;
	return change;
}

int main()
{
	string str;
	while(cin >> str)
	{
		if(str == "#") break;
		dict[str.length()].pb(str);
	}
	
	scanf("\n");
	int ans = 0;
	while(getline(cin,str))
	{
		string s = "";
		for(int i = 0; i < str.length(); i ++)
		{
			if(isalpha(str[i])) s += str[i];
			else
			{
				ans += output(s);
				s = "";
				cout<<str[i];
			}
		}
		if(s.length()) ans += output(s);
		cout<<endl;
	}
	cout<<ans<<endl;
}
