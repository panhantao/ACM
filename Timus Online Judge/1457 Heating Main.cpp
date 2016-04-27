#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	double n,temp;
	cin >> n;
	
	double sum = 0;
	for(int i = 0; i < n; i ++)
	{
		cin >> temp;
		sum += temp/n;
	}
	cout<<fixed<<setprecision(6)<<sum<<endl;
}