#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

struct Num
{
	int val;
	int pos;
}temp;

deque<Num> que;

int main()
{
	int k;
	scanf("%d",&k);
	
	for(int i = 1;; i ++)
	{
		scanf("%d",&temp.val);
		temp.pos = i;
		
		if(temp.val == -1)break;
		
		if(!que.empty() && que.front().pos + k == i)que.pop_front();
		while(1)
		{
			if(que.empty())break;
			
			if(temp.val >= que.back().val) que.pop_back();
			else break;
		}
		
		que.push_back(temp);
		
		if(i >= k)printf("%d\n",que.front().val);
	}
}
