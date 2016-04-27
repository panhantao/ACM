#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	long long a,b,c;
	while(scanf("%lld%lld%lld",&a,&b,&c) != EOF)
	{
		vector<long long> vec;
		vec.push_back(a); vec.push_back(b); vec.push_back(c);
		
		sort(vec.begin(),vec.end());
		
		if(vec[1]-vec[0] == 0)
		{
			printf("1\n");
			continue;
		}
		
		long long mi,ans=1;
		if(vec[1]-vec[0] < vec[2]-vec[1])
		{ 
			mi = vec[1]-vec[0];
			vec.push_back(vec[1]-vec[0]);
		}
		else
		{
			mi = vec[2]-vec[1];
			vec.push_back(vec[2]-vec[1]);
		}
		
		while(mi)
		{
			sort(vec.begin(),vec.end());
			for(int i = 1; i < vec.size(); i ++)
				if(vec[i]-vec[i-1] < mi)
					mi = vec[i]-vec[i-1];
			vec.push_back(mi);
			ans ++;
		}
		printf("%lld\n",ans);
	}
}
