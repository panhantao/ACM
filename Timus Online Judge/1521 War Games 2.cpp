#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 100005;

struct STNode
{
	int l,r,sum;
	STNode *lchild,*rchild;
}node[MAXN<<1],*root;

int z = 0;

STNode* build(int l,int r)
{
    STNode *tmp = &node[z ++];
    tmp->l = l; tmp->r = r; tmp->sum = r-l+1;
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

int update(STNode *root,int val)
{
	root->sum --;
	if(root->l == root->r)
	{
		root->sum = 0;
		return root->l;
	}

	if(val <= root->lchild->sum) return update(root->lchild,val);
	else return update(root->rchild,val-root->lchild->sum);
}

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k) != EOF)
    {
		z = 0;
        root = build(1,n);
        
        int pos,ans = 1;
        while(n --)
        {
            ans = (ans+k-1)%root->sum;
            if(ans == 0) ans = root->sum;
            pos = update(root,ans);
            printf("%d ",pos);
        }
        printf("\n");
    }
}
