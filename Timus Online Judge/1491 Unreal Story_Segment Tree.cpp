#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define ptf             printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define pf(x)           push_front(x)
#define mp              make_pair
#define MI(a,b)         a<b ? a:b
#define MX(a,b)         a<b ? b:a
#define LL              long long
#define PI              3.1415926535

const int MAXN = 100005;
struct STNode
{
	int l,r,sum,lazy;
	STNode *lchild,*rchild;
}node[MAXN<<1],*root;
int z,n;

STNode* build(int l,int r)
{
	STNode *tmp = &node[z ++];
	tmp->l=l; tmp->r=r; tmp->sum = tmp->lazy = 0;
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

void pass(STNode *root)
{
	if(!root->lazy) return ;
	root->lchild->lazy += root->lazy;
	root->lchild->sum += root->lazy;
	
	root->rchild->lazy += root->lazy;
	root->rchild->sum += root->lazy;
	
	root->lazy = 0;
}

void insert(STNode *root,int l,int r,int val)
{
	if(root->l==l && root->r==r)
	{
		root->lazy += val;
		root->sum += val;
		return ;
	}
	
	pass(root);
	
	int mid = (root->l+root->r) >> 1;
	if(r <= mid) insert(root->lchild,l,r,val);
	else if(l > mid) insert(root->rchild,l,r,val);
	else
	{
		insert(root->lchild,l,mid,val);
		insert(root->rchild,mid+1,r,val);
	}
}

int query(STNode *root,int pos)
{
	if(root->l == root->r) return root->sum;
	else
	{
		pass(root);
		int mid = (root->l+root->r) >> 1;
		if(pos <= mid) return query(root->lchild,pos);
		else return query(root->rchild,pos);
	}
}

int main()
{
	while(sf("%d",&n) != EOF)
	{
		z = 0;
		root = build(1,n);
		
		for(int i = 0; i <= n; i ++)
		{
			int a,b,c;
			sf("%d%d%d",&a,&b,&c);
			insert(root,a,b,c);
		}

		for(int i = 1; i < n; i ++)
			ptf("%d ",query(root,i));
		ptf("%d\n",query(root,n));
	}
}
