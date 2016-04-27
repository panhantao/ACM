#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

set<string> s;
set<string>::iterator p;

int main()
{
	int y,n,q;
	while(scanf("%d%d%d\n",&y,&n,&q) != EOF)
	{
		string str,ans = "",school;
		s.clear();
		for(int i = 0; i < n; i ++)
		{
			getline(cin,str);
			school = "";
			for(int j = 0; j < str.length(); j ++)
			{
				if(str[j]=='#') break;
				else school += str[j];
			}

			p = s.find(school);
			if(p == s.end())
			{
				s.insert(school);
				if(ans == "")
				{
					if(q-- == 0) ans = str;
				}
				else q --;
			}
		}
		cout<<ans<<endl;
	}
}
