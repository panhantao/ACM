#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<string>
using namespace std;

bool cmp(string a,string b)
{
	if(a.length() < b.length())return true;
	else return a < b;
}

int main()
{
	int n;
	string str;
	vector<string> vec;
	set<string> s,res;
	set<string>::iterator p;
	
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> str;
		p = s.find(str);
		if(p == s.end())s.insert(str);
		else res.insert(str);
	}
	
	for(p = res.begin(); p != res.end(); p ++)vec.push_back(*p);
	
	sort(vec.begin(),vec.end(),cmp);
	
	for(int i = 0; i < vec.size(); i ++)
		cout<<vec[i]<<endl;
		
	//system("pause");
}