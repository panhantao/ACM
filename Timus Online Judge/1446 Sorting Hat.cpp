#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

string name,house;
const string hname[] = {"Slytherin","Hufflepuff",
						"Gryffindor","Ravenclaw"};

int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int n;
	while(scanf("%d",&n) != EOF)
	{
		vector<string> vec[5];
		for(int i = 0; i < n; i ++)
		{
			scanf("\n");
			getline(cin,name);
			cin >> house;
			if(house == hname[0]) vec[0].push_back(name);
			else if(house == hname[1]) vec[1].push_back(name);
			else if(house == hname[2]) vec[2].push_back(name);
			else vec[3].push_back(name);
		}
		
		for(int i = 0; i < 4; i ++)
		{
			cout<<hname[i]<<":"<<endl;
			for(int j = 0; j < vec[i].size(); j ++)
				cout<<vec[i][j]<<endl;
			cout<<endl;
		}
	} 

}
