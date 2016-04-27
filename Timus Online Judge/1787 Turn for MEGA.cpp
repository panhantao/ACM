#include<iostream>
#include<queue>
using namespace std;

int main()
{
	queue<int> que;
	int k,n;
	cin >> k >> n;
	for(int i = 0; i < n; i ++)
	{
		int tmp;
		cin >> tmp;
		for(int i = 0; i < tmp; i ++) que.push(1);
		
		int count = k;
		while(!que.empty() && count)
		{
			que.pop();
			count --;
		}
	}
	cout<<que.size()<<endl;
	//system("pause");
}