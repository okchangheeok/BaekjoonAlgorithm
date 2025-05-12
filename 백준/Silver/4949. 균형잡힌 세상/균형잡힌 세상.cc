#include <bits/stdc++.h>
using namespace std;

string str;
bool flag;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	while(1){
		getline(cin, str);
		if(str == ".") break;
		
		stack<char> stk;
		for(char it: str){
			if(it == '(' || it == '[')
				stk.push(it);
			else if(it == ')'){
				if(stk.empty()) break;
				if(stk.top() != '(') break;
				stk.pop();
			}
			else if(it == ']'){
				if(stk.empty()) break;
				if(stk.top() != '[') break;
				stk.pop();
			}
			if(it == '.' && stk.empty()) flag = true;
		}
		
		if(flag)	cout << "yes\n";
		else		cout << "no\n";
		
		flag = false;
	}
	return 0;
}