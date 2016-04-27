#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int map[55][55],basex[1005],basey[1005];
double r[1005];
bool v[55][55];

int main()
{
	int m,n,k;
	scanf("%d%d%d",&n,&m,&k)  ;
	//while(scanf("%d%d%d",&m,&n,&k) != EOF){
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				scanf("%d",&map[i][j]);

		memset(v,false,sizeof(v));
		for(int i = 1; i <= k; i ++)
		{
			scanf("%d%d%lf",&basex[i],&basey[i],&r[i]);
			v[basex[i]][basey[i]] = true;
		}
		
		long long ans = 0;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
				if(!v[i][j])
				{
					int Hmax = 0x3FFFFFFF,Hmin = -1;
					bool valid = true; //v[i][j] = true;
					for(int a = 1; a <= k; a ++)
					{
						// 水平距离d
						double d = (i-basex[a])*(i-basex[a])+(j-basey[a])*(j-basey[a]);
						
						if(d - r[a]*r[a] > 0) { valid=false; break; } // 水平距离大于辐射半径 
						
						int ext = int(sqrt(r[a]*r[a]-d));		// 辐射垂直延伸距离 
		
						int hmax = map[basex[a]][basey[a]]+ext;
						int hmin = map[basex[a]][basey[a]]-ext;
						
						//if(hmax < map[i][i]) { valid=false; break; }	// 向上延伸也达不到山的高度 
						
						hmin = hmin > map[i][j] ? hmin : map[i][j];
						
						Hmax = min(Hmax,hmax);
						Hmin = max(Hmin,hmin);
					}
					if(valid && Hmax>=Hmin)
					{
						ans += Hmax-Hmin+1;
						//printf("[%d,%d],%d,%d\n",i,j,Hmin,Hmax);
					}
				}
		printf("%lld\n",ans);	
	//}
}
