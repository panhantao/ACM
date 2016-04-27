#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

#define REP(i,o,b,d) for(int i = o; i < b; i += d)
#define MS(x,val) memset(x,val,sizeof(x))
#define pb(x) push_back(x);

map<int,int> m;
map<int,int>::iterator p;

const int MAXN = 100005;
struct STNode
{
	int l,r,cnt,gcd;
	STNode *lchild,*rchild;
}node[MAXN<<1],*root;
char opt[MAXN];
int num[MAXN],z;

int GCD(const int &m,const int &n)
{
	if(m<n) return GCD(n,m);
	if(m%n==0) return n;
	return GCD(n,m%n);
}

STNode* build(int l,int r)
{
	STNode *tmp = &node[z++];
	tmp->l = l; tmp->r = r; tmp->gcd = -1; tmp->cnt = 0;
	if(l == r)
	{
		tmp->lchild = tmp->rchild = NULL;
	}
	else
	{
		int mid = (l+r) >> 1;
		tmp->lchild = build(l,mid);
		tmp->rchild = build(mid+1,r);
	}
	return tmp;
}

void update(STNode *root,int val,int pos,int opt)
{
	root->cnt += opt;
	if(root->l==pos && root->r==pos)
	{
		if(root->cnt == 0) root->gcd = -1;
		else root->gcd = val;
		return ;
	}
	else
	{
		int mid = (root->l+root->r) >> 1;
		if(pos <= mid) update(root->lchild,val,pos,opt);
		else update(root->rchild,val,pos,opt);
	}

	if(root->lchild->gcd == -1) root->gcd = root->rchild->gcd;
	else if(root->rchild->gcd == -1)root->gcd = root->lchild->gcd;
	else root->gcd = GCD(root->lchild->gcd,root->rchild->gcd);
}

int main()
{
	int q;
	while(scanf("%d",&q) != EOF)
	{
		int c = 1;
		m.clear();
		REP(i,0,q,1)
		{
			scanf("\n");
			scanf("%c%d",&opt[i],&num[i]);
			m[num[i]] = 1;
		}

		for(p = m.begin(); p != m.end(); p ++) p->second = c++;

		z = 0;
		root = build(1,c-1);

		REP(i,0,q,1)
		{
			if(opt[i] == '+') update(root,num[i],m[num[i]],1);
			else update(root,num[i],m[num[i]],-1);

			if(root->gcd == -1) printf("1\n");
			else printf("%d\n",root->gcd);
		}
	}
}
