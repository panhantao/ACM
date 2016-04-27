#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Prob
{
	string name[5];
	int id;
}arr[20];

int order[20];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n;
	while(cin >> n)
	{
		for(int i = 1; i <= n; i ++)
		{
			arr[i].id = i;
			cin >> arr[i].name[0] >> arr[i].name[1] >> arr[i].name[2];
		}
		for(int i = 1; i <= n; i ++) cin >> order[i];

		vector<string> vec;
		
		string now = min(arr[order[1]].name[0],min(arr[order[1]].name[1],arr[order[1]].name[2]));
		vec.push_back(now);

		for(int i = 2; i <= n; i ++)
		{
			vector<string> tmp;
			for(int j = 0; j < 3; j ++)
				if(arr[order[i]].name[j] > now)
					tmp.push_back(arr[order[i]].name[j]);
					
			if(tmp.size() == 0) break;
			
			now = tmp[0];
			for(int j = 1; j < tmp.size(); j ++) now = min(now,tmp[j]);
			vec.push_back(now);
		}

		if(vec.size() < n) cout << "IMPOSSIBLE" << endl;
		else
		{
			for(int i = 0; i < n; i ++)
				cout<<vec[i]<<endl;
		}
	}
}
