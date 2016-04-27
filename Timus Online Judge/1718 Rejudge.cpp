#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

set<string> mxs,mis;
set<string>::iterator p;

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		mxs.clear(); mis.clear();

		string name,status;
		int c;
		for(int i = 0; i < n; i ++)
		{
			cin >> name >> status;
			if(status=="ML" || status=="WA" || status=="TL")
			{
				cin >> c;
				if(c == 7)
				{
					mis.insert(name);
					mxs.insert(name);
				}
				else if(c == 6)
				{
					mxs.insert(name);
				}
			}
			
			if(status=="AC")
			{
				mxs.insert(name);
			}
		}
		printf("%d %d\n",mis.size(),mxs.size());
	}
}
