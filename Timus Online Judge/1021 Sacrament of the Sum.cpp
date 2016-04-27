#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 50005;
int A[MAXN],B[MAXN],a,b;

int main()
{
	scanf("%d",&a);
	for(int i = 0; i < a; i ++) scanf("%d",&A[i]);
	scanf("%d",&b);
	for(int i = 0; i < b; i ++) scanf("%d",&B[i]);
	
	int ia=0,ib=0;
	bool yes = false;
	
	for(ia; ia < a; ia ++)
	{
		for(ib; ib < b; )
		{
			if(A[ia]+B[ib] == 10000)
			{
				yes = true;
				goto res;
			}
			else if(A[ia]+B[ib] < 10000) break;
			else ib ++;
		}
	}
	
	res:
	if(yes) printf("YES\n");
	else printf("NO\n");
	
	//system("pause");
}
