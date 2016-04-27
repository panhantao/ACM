#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string str[1000];
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> str[i];
	
	sort(str,str+n);
	
	char k;
	cin >> k;
	for(int i = 0; i < n; i ++)
		if(str[i][0] == k)cout<<str[i]<<endl;
	//system("pause");
}