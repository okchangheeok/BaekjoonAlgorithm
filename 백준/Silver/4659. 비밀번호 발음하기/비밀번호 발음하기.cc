#include <bits/stdc++.h>

using namespace std;

string str;

bool r1(string s){
	for(auto i: s)
		if(i == 'a'|| i == 'e'|| i == 'i'|| i == 'o'|| i == 'u')
			return true;
	return false;
}

bool r2(string s){
	int m = 0;
	int j = 0;
	if(s.size() > 2){
		for(auto i: s){
			if(i == 'a'|| i == 'e'|| i == 'i'|| i == 'o'|| i == 'u'){
				m++; j = 0;
			}
			else{
				j++; m = 0;
			}
			if(j == 3 || m == 3)
				return false;
		}
	}
	return true;
}

bool r3(string s){
	char c = '0';
	for(auto i: s){
		if(i == c)
			if(i != 'e' && i != 'o')
				return false;
		c = i;
	}
	return true;
}

void ac(string s){
	cout << "<" << s << "> is acceptable.\n";
}

void nac(string s){
	cout << "<" << s << "> is not acceptable.\n";
}

int main()
{
    while(1){
    	cin >> str;
    	if(str == "end")
    		break;
    	if(r1(str) && r2(str) && r3(str))
    		ac(str);
    	else
    		nac(str);
	}
    return 0;
}