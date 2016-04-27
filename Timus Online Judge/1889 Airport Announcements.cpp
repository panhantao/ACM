#include<iostream>
#include<cstdio>
#include<set>
#include<string>
using namespace std;

string str[1005];
int n;

set<string> group[1005],lang;
set<string>::iterator p;

bool check(int x)
{	
	lang.clear();
	for(int i = 0; i < 1005; i ++) group[i].clear();
	
	int g = 1;
	for(int i = 1; i <= n; i ++)
	{
		if(str[i] != "unknown")
		{
			group[g].insert(str[i]);
		}
		if(i%(n/x) == 0)
		{
			if(group[g].size() > 1) return false;
			if(group[g].size())
			{
				p = lang.find(*group[g].begin());
				if(p != lang.end()) return false;
				else lang.insert(*group[g].begin());
			}
			g ++;
		}
	}
	return true;
}


int main()
{
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 1; i <= n; i ++) cin >> str[i];
		
		bool wrong = true;
		for(int i = 1; i <= n; i ++)
			if(n%i == 0)
			{
				if(check(i))
				{
					printf("%d ",i);
					wrong = false;
				}
			}
		if(wrong) printf("Igor is wrong.");
		printf("\n");
	}
}
