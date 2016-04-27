#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<int,int> m;
map<int,int>::iterator p;

int n,tmp;

int main()
{
	for(int i = 0; i < 3; i ++)
	{
		scanf("%d",&n);
		for(int j = 0; j < n; j ++)
		{
			scanf("%d",&tmp);
			m[tmp] ++;
		}
	}
	
	int num = 0;
	for(p = m.begin(); p != m.end(); p ++)
		if(p->second == 3)
			num ++;
	printf("%d\n",num);
	//system("pause");
}