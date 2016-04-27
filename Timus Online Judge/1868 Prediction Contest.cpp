#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

map<string,string> m;
map<string,string>::iterator p;
string tmp;

int sum[20] = {0};

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	for(int i = 1; i <= 12; i ++)
	{
		cin >> tmp;
		if(i <= 4) m[tmp] = "gold";
		else if(5<=i && i<= 8) m[tmp] = "silver";
		else m[tmp] = "bronze";
	}
	
	int n;
	cin >> n;
	while(n --)
	{
		int num; cin >> num;
		int hits=0;
		string school,medal,ch;
		
		for(int i = 0; i < num; i ++)
		{
			cin >> school >> ch >> medal;
			if(medal == m[school]) hits ++;
		}
		sum[hits] ++;
	}

	int ans = 0;
	for(int i = 15; i >= 0; i --)
		if(sum[i])
		{
			ans += sum[i]*5;
			break;
		}
	printf("%d\n",ans);

}
