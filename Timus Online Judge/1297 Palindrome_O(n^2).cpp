#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char text[3000];
int ptr=0;
char ch;

int main()
{
	text[ptr++] = '#';
	while(scanf("%c",&ch) != EOF)
	{
		text[ptr++] = ch;
		text[ptr++] = '#';
	}
	text[ptr] = '\0';
	
	string res = "";
	int textlen = strlen(text)-1;
	int reslen=0;
	
	int begpos,endpos;
	for(int i = 1; i < textlen; i ++)
	{
		int bptr=i-1,fptr=i+1,curlen=1;
		
		while(fptr < textlen && bptr >= 0)
		{
			if(text[bptr] == text[fptr])
			{
				bptr --;
				fptr ++;
				curlen += 2;
			}
			else break;
		}
		
		if(curlen > reslen)
		{
			begpos = bptr+1;
			endpos = fptr-1;
			reslen = curlen;
		}
	}

	for(int i = begpos; i <= endpos; i ++) res += text[i];

	for(int i = 0; i < res.length(); i ++)
		if(res[i] != '#')
			printf("%c",res[i]);
	
	printf("\n");
}
