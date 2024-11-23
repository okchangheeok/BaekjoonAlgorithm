#include <bits/stdc++.h>

using namespace std;

int a[26];
string S;

int main(){
	cin >> S;
	for(char it: S)
		a[it - 'a']++;
	
	for(int it: a)
		cout << it << " ";
	
	return 0;
}