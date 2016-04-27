#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int tox[] = {-1,1,2,2,1,-1,-2,-2};
int toy[] = {2,2,1,-1,-2,-2,-1,1};

int main()
{
	int testcase;
	cin >> testcase;
	char a,b;
	int x,y;
	
	while(testcase --)
	{
		int count = 0;
		cin >> a >> b;
		x = a - 'a';
		y = b - '1';
		
		for(int i = 0; i < 8; i ++)
			if(x + tox[i] >= 0 && x + tox[i] < 8 && y + toy[i] >= 0 && y + toy[i] < 8)
				count ++;
				
		cout<<count<<endl;
	}
}
