#include<iostream>
#include<cstdio>
#include<set>
#include<string>
using namespace std;

int main()
{
	int n;
	scanf("%d\n",&n);
	
	set<string> s;
	set<string>::iterator p;
	string str;
	
	int ans = 0;
	for(int i = 0; i < n; i ++)
	{
		getline(cin,str);
		if(s.find(str) == s.end()) s.insert(str);
		else ans ++;
	}
	cout << ans << endl;
}
