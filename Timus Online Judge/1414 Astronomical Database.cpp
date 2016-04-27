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

set<string> s;
set<string>::iterator p;

char opt;
string str = "sun";

bool cmp(string a)
{
	for(int i = 0; i < str.length(); i ++)
		if(a[i] != str[i])
			return false;
	return true;
}

int main()
{
	s.insert(str);
	while(cin >> opt)
	{
		cin >> str;
		if(opt == '+')
		{
			s.insert(str);
		}
		else
		{
			cout<<str<<endl;
			p = lower_bound(s.begin(),s.end(),str);
			int c = 0;
			for(; p != s.end() && c < 20; p ++,c ++)
				if(cmp(*p))
					cout<<"  "<<*p<<endl;
		}
	}
}
