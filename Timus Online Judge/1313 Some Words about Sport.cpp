#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
	int n,i,j;
	cin >> n;
	int arr[200][200];
	
	int k = 1;
	
	for(i = 0; i < n; i ++)
		for(j = 0; j < n; j ++)
			cin >> arr[i][j];
	
	
	vector<int> vec;
	for(i = 0; i <= (n-1) * (n-1); i ++)
	{
		for(int row = 0; row < n; row ++)
			for(int col = 0; col < n; col ++)
				if(row + col == i)
				{
					vec.push_back(arr[col][row]);
				}
	}
	
	for(i = 0; i < vec.size()-1; i ++) cout<< vec[i] << " ";
	cout<<vec[vec.size()-1]<<endl;
	
	//system("pause");
}
