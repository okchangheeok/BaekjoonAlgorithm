#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
		string str;
		stack<char> stk;
		bool flag = 1;
		
    	cin >> str;
    	for(auto it: str){
    		if(it == '(')	stk.push(it);
    		else{
    			if(stk.empty()){
    				flag = 0;
    				break;
				}
				else stk.pop();
			}
		}
		
		if(flag && stk.empty())	cout << "YES\n";
		else					cout << "NO\n";
	}
    
	return 0;
}