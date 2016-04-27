#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
	string str;
	int e=0,m=0,l=0;
	int n;
	cin >> n;
	scanf("\n");
	for(int i = 0; i < n; i ++)
	{
		getline(cin,str);
		if(str == "Emperor Penguin") e ++;
		else if(str == "Macaroni Penguin") m ++;
		else l ++;
	}

	int max;
	if(e > m)
	{
		max = e;
		str = "Emperor Penguin";
	}
	else
	{
		max = m;
		str = "Macaroni Penguin";
	}
	
	if(l > max) str = "Little Penguin";
	
	cout<<str<<endl;
	//system("pause");
}
