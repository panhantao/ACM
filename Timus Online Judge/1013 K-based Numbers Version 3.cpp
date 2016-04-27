#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string dp[2000];

string Add(string a,string b)
{
	a.insert(0,1,'0');
	while(b.length() != a.length()) b.insert(0,1,'0');
	for(int i = a.length()-1; i > 0; i --)
	{
		int tmp = a[i]+b[i]-'0'-'0';
		if(tmp > 9)
		{
			b[i] = tmp%10+'0';
			b[i-1] ++;
		}
		else b[i] = tmp+'0';
	}
	if(b[0] == '0') b.erase(0,1);
	return b;
}

string Mul(int a,string b)
{
	if(a == 1) return b;
	
	int c = 0;
	for(int i = b.length()-1; i >= 0; i --)
	{
		int tmp = a*(b[i]-'0')+c;
		if(tmp > 9)
		{
			b[i] = tmp%10+'0';
			c = tmp/10;
		}
		else
		{
			b[i] = tmp+'0';
			c = 0;
		}
	}
	if(c > 0) b.insert(0,1,c+'0');
	return b;
}

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		for(int i = 0; i < 2000; i ++) dp[i] = "";
		dp[0] = "1"; dp[1] += (k-1)+'0';
		
		for(int i = 2; i <= n; i ++)
			dp[i] = Mul( (k-1),Add(dp[i-1],dp[i-2]) );
			
		cout<<dp[n]<<endl;
	}
}
