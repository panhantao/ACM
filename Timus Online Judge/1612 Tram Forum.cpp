#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string,int> m;
map<string,int>::iterator p;
string str;

int main()
{
	while(cin >> str)
	{
		string tmp="";
		for(int i = 0; i < str.length(); i ++)
		{
			if(isalpha(str[i])) tmp += str[i];
			else
			{
				m[tmp] ++; tmp = "";
			}
		}
		if(tmp != "") m[tmp] ++;
	}

	int a = m["tram"], b = m["trolleybus"];

	if(a != b)
	{
		if(a > b) cout << "Tram driver" << endl;
		else cout << "Trolleybus driver" << endl;
	}
	else
	{
		cout << "Bus driver" << endl;
	}
}
