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
	
	for(i = 0; i <= (n-1) * (n-1); i ++)
	{
		for(int row = 0; row < n; row ++)
			for(int col = 0; col < n; col ++)
				if(row + col == i)
				{
					arr[row][col] = k;
					k ++;
				}
	}
	
	for(i = 0; i < n; i ++)
	{
		for(j = n-1; j > 0; j --)
			cout<<arr[i][j]<<" ";
		cout<<arr[i][j]<<endl;
	}
	
	//system("pause");
}
