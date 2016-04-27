#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main()
{
	map<int,int> m;
	map<int,int>::iterator p;
	
	int n,temp;
	cin >> n;
	
	for(int i = 0; i < n; i ++)
	{
		scanf("%d",&temp);
		p = m.find(temp);
		
		if(p == m.end())
			m[temp] = 1;
		else
			p->second ++;
	}
	
	int max = m.begin()->first,maxtime = m.begin()->second;
	for(p = m.begin(); p != m.end(); p ++)
		if(p->second > maxtime)
		{
			maxtime = p->second;
			max = p->first;
		}
		
	cout<<max<<endl;
	
	//system("pause");
}