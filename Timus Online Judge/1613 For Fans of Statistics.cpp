#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<int,vector<int> > m;
map<int,vector<int> >::iterator p;
vector<int>::iterator vp;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
	{
		int tmp;
		scanf("%d",&tmp);
		m[tmp].push_back(i);
	}
	
	int q;
	scanf("%d",&q);
	for(int i = 0; i < q; i ++)
	{
		int l,r,val;
		scanf("%d%d%d",&l,&r,&val);
		p = m.find(val);
		if(p == m.end())printf("0");
		else
		{
			vp = lower_bound(p->second.begin(),p->second.end(),l);
			if(vp == p->second.end() || (*vp) > r)printf("0");
			else printf("1");
		}
	}
	printf("\n");
}
