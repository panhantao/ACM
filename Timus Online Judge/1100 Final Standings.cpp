#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
	int id;
	int solved;
	int no;
}arr[150005];

bool cmp(Node a, Node b)
{
	if(a.solved > b.solved) return true;
	else if(a.solved < b.solved) return false;
	
	if(a.no < b.no) return true;
	else if(a.no > b.no) return false;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		scanf("%d%d",&arr[i].id,&arr[i].solved);
		arr[i].no = i;
	}
	
	sort(arr,arr+n,cmp);
	
	for(int i = 0; i < n; i ++)
		printf("%d %d\n",arr[i].id,arr[i].solved);
		
	//system("pause");
}
