#include <bits/stdc++.h>

using namespace std;

int N, flag, b, len;
string s;
vector<string> vs;

bool compare(string a, string b){
	if(a.size() != b.size())
		return a.size() < b.size();
	else{
		for(int i = 0; i < a.size(); i++){
			if(a[i] != b[i])
				return (a[i] < b[i]);
		}
		return 1;
	}
}

int main()
{
    cin >> N;
    while(N--){
    	cin >> s;
    	for(int i = 0; i < s.size(); i++){
    		if(flag == 0 && s[i] == '0'){
    			if(!('0' <= s[i + 1] && s[i + 1] <= '9'))
    				vs.push_back("0");
    		}
			else if(flag == 0 && '1' <= s[i] && s[i] <= '9'){
    			flag = 1;
    			b = i;
			}
			else if(flag == 1 && (s[i] < '0' || '9' < s[i])){
				flag = 0;
				len = i - b;
				vs.push_back(s.substr(b, len));
			}
			
		}
		if(flag == 1){
			flag = 0;
			len = s.size() - b;
			vs.push_back(s.substr(b, len));
		}
	}
	
	sort(vs.begin(), vs.end(), compare);
	
	for(auto it: vs){
		cout << it << "\n";
	}

    return 0;
}