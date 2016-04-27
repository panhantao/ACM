#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[105],b[105];
bool cmp(int a,int b) { return a > b; }

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		int ans = 0;
		
		for(int i = 0; i < n; i ++) 
		{
			scanf("%d",&a[i]);
			ans += a[i];
		}
		for(int i = 0; i < m; i ++)
		{
			scanf("%d",&b[i]);
		}
		
		sort(a,a+n,cmp); sort(b,b+m,cmp);
		
		int bound = n<m ? n:m;
		
		for(int i = 0; i < bound; i ++)
		{
			int tmp = 0;
			for(int j = i+1; j < n; j ++) tmp += a[j];
			for(int j = i+1; j < m; j ++) tmp += (i+1)*b[j];
			
			ans = ans<tmp ? ans:tmp;
		}
		printf("%d\n",ans);
	}
}
