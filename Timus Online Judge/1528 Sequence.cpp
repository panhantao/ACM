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

// g(n) = n , f(n) = n!

int main()
{
    int n,p;
    while(sf("%d%d",&n,&p) && n)
    {
        if(p <= n)
        {
            ptf("0\n");
            continue; 
        }
        
        LL ans = 1;
        for(int i = 2; i <= n; i ++)
        {
            ans *= (i%p);
            ans %= p;
            if(ans == 0) break;
        }
        
        ptf("%lld\n",ans);
    }
}
