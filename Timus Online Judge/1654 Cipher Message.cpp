#include<stdio.h>

int main()
{
	char sta[200005];
	int size = 0;
	
	char ch;
	while(scanf("%c",&ch) != EOF)
	{
		if(size == 0) sta[size ++] = ch;
		else
		{
			if(size != 0 && sta[size-1] == ch)
				size --;
			else
				sta[size ++] = ch;
		}
	}
	int i;
	for(i = 0; i < size; i ++)
		printf("%c",sta[i]);
}