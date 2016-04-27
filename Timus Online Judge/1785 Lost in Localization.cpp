#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if(1 <= n && n <= 4) cout<<"few"<<endl;
	else if(5 <= n && n <= 9) cout<<"several"<<endl;
	else if(10 <= n && n <= 19) cout<<"pack"<<endl;
	else if(20 <= n && n <= 49) cout<<"lots"<<endl;
	else if(50 <= n && n <= 99) cout<<"horde"<<endl;
	else if(100 <= n && n <= 249) cout<<"throng"<<endl;
	else if(250 <= n && n <= 499) cout<<"swarm"<<endl;
	else if(500 <= n && n <= 999) cout<<"zounds"<<endl;
	else if(1000 <= n) cout<<"legion"<<endl;
	
//	system("pause");
}