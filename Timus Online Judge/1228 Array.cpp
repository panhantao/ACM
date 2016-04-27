#include<iostream>
using namespace std;

int main()
{
	int n,s,d;
	cin >> n >> s;
	
	for(int i = 0; i < n;i ++)
	{
		cin >> d;
		cout << s/d - 1 << " ";
		s = d; 
	}
}
