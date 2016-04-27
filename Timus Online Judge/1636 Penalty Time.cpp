#include<iostream>
#include<cstdio>
#include<set>
#include<string>
using namespace std;

int main()
{
	int t1,t2;
	cin >> t1 >> t2;
	
	int temp;
	for(int i = 0; i < 10; i ++)
	{
		cin >> temp;
		t2 -= temp * 20;
	}
	
	if(t1 <= t2)cout<<"No chance."<<endl;
	else cout<<"Dirty debug :("<<endl;
}