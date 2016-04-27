#include<iostream>
using namespace std;

int meter[105] = {0};
int n;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int tmp;
		cin >> tmp;
		meter[tmp-600] ++;
	}
	
	int count = 0;
	for(int i = 0; i < 105; i ++)
		count += meter[i]/4;
	cout<<count<<endl;
}