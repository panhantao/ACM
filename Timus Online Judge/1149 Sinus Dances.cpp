#include<iostream>
using namespace std;

void a(int n,int num)
{
	cout<<"sin("<<num;
	if(num < n)
	{
		if(num % 2 == 0)cout<<"+";
		else cout<<"-";
		a(n,num+1);
	}
	cout<<")";
}

void s(int n,int num)
{
	if(num < n)
	{
		cout<<"(";
		s(n,num+1);
		cout<<")";
	}
	a(n-num+1,1);
	cout<<"+"<<num;
}

int main()
{
	int n;
	cin >> n;
	s(n,1);
	//system("pause");
}
