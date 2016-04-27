#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

struct Opt
{
	int l,r;
	char c;
}opt[5010];

struct Line
{
	char lc,rc;
}line[10010];

int n,num=1;
int h[10010];

set<int> s;
set<int>::iterator p;

int find(int x)
{
	int l=1,r=num;
	while(l <= r)
	{
		int mid = (l+r)>>1;
		if(h[mid] == x) return mid;
		else if(h[mid] < x) l = mid+1;
		else r = mid-1;
	}
}

void paint()
{
	for(int i = 0; i < n; i ++)
	{
		int left = find(opt[i].l),right = find(opt[i].r);
		line[left].rc = line[right].lc = opt[i].c;
		for(int j = left+1; j < right; j ++)
			line[j].lc = line[j].rc = opt[i].c;
	}
}

void ans()
{
	int beg,end,curlen,maxlen=0,i,j;
	for(i = 0; i < num; i ++)
	{
		if(line[i].rc == 'w')
		{
			curlen = 0;
			for(j = i+1; j < num; j ++)
			{
				if(line[j].lc=='w' && line[j].rc=='w')
				{
					curlen += h[j]-h[j-1];
					continue;
				}
				else if(line[j].lc=='w')
				{
					curlen += h[j]-h[j-1];
				}
				
				if(curlen > maxlen)
				{
					beg = i;
					if(line[j].lc=='b') end = j-1;
					else end = j;
					maxlen = curlen;
				}
				break;
			}
		}
	}
	
	printf("%d %d\n",h[beg],h[end]);
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
	{
		scanf("%d %d %c",&opt[i].l,&opt[i].r,&opt[i].c);
		s.insert(opt[i].l);
		s.insert(opt[i].r);
	}
	
	for(p = s.begin(); p !=s.end(); p ++) h[num++] = *p;
	h[0] = 0;
	h[num ++] = 1000000000; h[num ++] = 1000000001;
	memset(line,'w',sizeof(line));
	line[num-1].rc = line[num-1].lc = 'b';
	
	paint();
	ans();
	system("pause");
}
