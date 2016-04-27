#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

long double arr[2000000];

int main()
{
	
	int i = 0;
	while(cin >> arr[i])
		i ++;
	
	for(int j = i -1; j >= 0 ; j --)
		cout<<fixed<<setprecision(4)<<sqrt(arr[j])<<endl;
}
