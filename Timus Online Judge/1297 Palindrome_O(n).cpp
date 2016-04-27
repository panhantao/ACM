#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN = 3000;

char str[MAXN];
int rad[MAXN];
int maxlen,midpos;

void Manacher(int n)
{
    int i,id,mx = 0;

    for(i=1; i<n; i++)
    {
        if( mx > i )
            rad[i] = min( rad[(id<<1)-i], mx-i);
        else
            rad[i] = 1;
        
        while(str[i+rad[i]]==str[i-rad[i]] && i+rad[i] < n && i-rad[i] > 0)
            rad[i] ++;
        
        if( rad[i]+i > mx )
        {
            mx = rad[i]+i;
            id = i;
        }
        if(rad[i] > maxlen)
		{
			maxlen = rad[i];
			midpos = i;
		}
    }
}

int main()
{
    char ch[MAXN];
    while(scanf("%s",&ch) != EOF)
    {
        str[1] = str[0] = '#';
		int n=2;
        int len = strlen(ch);
        for(int i = 0; i < len; i ++)
        {
            str[n ++] = ch[i];
            str[n ++] = '#';
        }
        
        str[n] = '\0';
        Manacher(n);
        
        for(int i = midpos-maxlen+1; i < midpos+maxlen; i ++)
        	if(str[i] != '#')
        		printf("%c",str[i]);
        printf("\n");
    }
}
