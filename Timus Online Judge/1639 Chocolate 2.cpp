#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int num = n*m;
	if(num % 2 == 0)cout<<"[:=[first]"<<endl;
	else cout<<"[second]=:]"<<endl;
}