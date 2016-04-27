#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

set<string> s;
string str;

int main()
{
	cin >> str;
	s.insert(str);
	while(cin>>str && str!="#")
	{
		int pos = str.find('-');
		int len = str.length();
		s.insert(str.substr(0,pos));
		s.insert(str.substr(pos+1,len-1));
	}
	
	if(s.size() == 0) printf("0\n");
	else printf("%d\n",s.size()-1);
}
