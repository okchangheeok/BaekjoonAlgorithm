#include <iostream>
using namespace std;

string s;
int ans;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	while(1){
		cin >> s;
		
		if(s == "0") break;
		
		ans += s.size() + 1;
		
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '1') ans += 2;
			else if(s[i] == '0') ans += 4;
			else ans += 3;
		}
		
		cout << ans << "\n";
		ans = 0;
	}
	
    return 0;
}