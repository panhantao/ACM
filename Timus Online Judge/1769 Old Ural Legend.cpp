#include<iostream>
#include<cstdio>
#include<string>
#include<memory.h>
using namespace std;

string str;
bool posib[100000];

string tostr(int x)
{
	string tmp = "";
	while(x)
	{
		tmp.insert(0,1,x%10+'0');
		x /= 10;
	}
	return tmp;
}

int toint(string x)
{
	int ans = 0;
	for(int i = 0; i < x.length(); i ++)
	{
		ans *= 10;
		ans += x[i]-'0';
	}
	return ans;
}

bool find(string x)
{
	for(int i = 0; i < str.length(); i ++)
	{
		bool match = true;
		for(int j = 0; j < x.length(); j ++)
		{
			if(str[i+j] != x[j])
			{
				match = false;
				break;
			}
		}
		if(match) return true;
	}
	return false;
}

void init()
{
	memset(posib,true,sizeof(posib));
	for(int i = 0; i < str.length(); i ++)
	{
		string tmp = "";
		for(int j = 0; j < 5; j ++)
		{
			if(i+j < str.length())
			{
				tmp += str[i+j];
				posib[toint(tmp)] = false;
			}
			else break;
		}
	}
}

int main()
{	
	while(cin >> str)
	{
		init();
		for(int i = 0;; i ++)
		{
			if(posib[i] && !find(tostr(i)))
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}
