#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int n1,c1,n2,t,c2,n3;
	while(scanf("%d%d%d%d%d%d",&n1,&c1,&n2,&t,&c2,&n3) != EOF)
	{
		int tot = 0;
		
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i ++)
		{
			int mm,ss;
			scanf("%d:%d",&mm,&ss);
			if(mm==0 && ss <= 6) continue;
			if(ss > 0) mm ++;
			tot += mm;
		}
		
		printf("Basic:     %d\n",tot*c1+n1);
		printf("Combined:  %d\n",max(0,tot-t)*c2+n2);
		printf("Unlimited: %d\n",n3);
	}
}
