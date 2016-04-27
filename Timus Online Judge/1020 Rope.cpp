#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct point
{
	double x,y;
}arr[105];

int main()
{
	int n;
	double r,sum = 0;
	cin >> n >> r;
	
	cin >> arr[0].x >> arr[0].y;
	
	for(int i = 1; i < n; i ++)
	{
		cin >> arr[i].x >> arr[i].y;
		sum += sqrt((arr[i].x - arr[i-1].x) * (arr[i].x - arr[i-1].x) + (arr[i].y - arr[i-1].y) * (arr[i].y - arr[i-1].y));
	}
	
	sum += sqrt((arr[n-1].x - arr[0].x)*(arr[n-1].x - arr[0].x)+(arr[n-1].y - arr[0].y)*(arr[n-1].y - arr[0].y));
	sum += 2 * 3.141592535 * r;
	
	cout<<fixed<<setprecision(2)<<sum<<endl;
	//system("pause");
	
}
