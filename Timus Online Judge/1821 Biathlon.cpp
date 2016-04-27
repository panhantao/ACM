#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Name
{
	string name;
	double rt,ft;
	friend bool operator<(const Name &a,const Name &b)
	{
		return a.ft < b.ft;
	}
}arr[105];

string name;
int mm;
double ss,best;
vector<string> vec;

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < n; i ++)
		{
			cin >> arr[i].name;
			scanf("%d:%lf",&mm,&ss);
			arr[i].rt = mm*60+ss;
			arr[i].ft = mm*60+ss + 30*i;
		}
		
		sort(arr,arr+n);
		
		vec.clear();
		best = 0x3FFFFFFF;
		for(int i = 0; i < n; i ++)
		{
			if(arr[i].rt < best)
			{
				vec.push_back(arr[i].name);
				best = arr[i].rt;
			}
		}
		
		sort(vec.begin(),vec.end());
		
		cout<<vec.size()<<endl;
		for(int i = 0; i < vec.size(); i ++)
			cout<<vec[i]<<endl;
	}
}
