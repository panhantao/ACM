#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int n;
int id = 0;
int visited[305];

string list[305];
int level[305];
vector<int> graph[305];
map<string,int> m;
map<string,int>::iterator p;

void bfs(int x)
{
	memset(visited,false,sizeof(visited));
	memset(level,-1,sizeof(level));
	
	visited[x] = true; level[x] = 0;
	
	queue<int> node;	node.push(x);
	queue<int> l;		l.push(0);

	while(!node.empty())
	{
		int curnode = node.front();		node.pop();
		int curl = l.front();			l.pop();
		level[curnode] = curl;
		for(int i = 0; i < graph[curnode].size(); i ++)
		{
			int next = graph[curnode][i];
			if(!visited[next])
			{
				visited[next] = true;
				node.push(next);
				l.push(curl+1);
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
	{
		string str;
		int num[4];
		for(int j = 0; j < 3; j ++)
		{
			cin >> str;
			p = m.find(str);
			if(p == m.end())
			{
				m[str] = id;
				num[j] = id ++;
			} 
			else
				num[j] = p->second;
		}
		
		graph[num[0]].push_back(num[1]);
		graph[num[0]].push_back(num[2]);
		graph[num[1]].push_back(num[0]);
		graph[num[1]].push_back(num[2]);
		graph[num[2]].push_back(num[0]);
		graph[num[2]].push_back(num[1]);
	}
	
	int beg = -1;
	for(p = m.begin(); p != m.end(); p ++)
	{
		list[p->second] = p->first;
		if(p->first == "Isenbaev") 
			beg = p->second;
	}
	
	if(beg != -1)
	{
		bfs(beg);
		for(int i = 0; i < m.size(); i ++)
			m[list[i]] = level[i];
	
		for(p = m.begin(); p != m.end(); p ++)
		{
			if(p->second == -1)
				cout<<p->first<<" undefined"<<endl;
			else
				cout<<p->first<<" "<<p->second<<endl;
		}
	}
	else
	{
		for(p = m.begin(); p != m.end(); p ++)
			cout<<p->first<<" undefined"<<endl;
	}
	//system("pause");
}
