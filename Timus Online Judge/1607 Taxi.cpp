#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	
	while(a < c)
	{
		if(a + b < c)
			a += b;
		else
			a = c;
			
		if(c - d > a)
			c -= d;
		else
			c = a;
	}
	cout << a << endl;
	system("pause");
}
