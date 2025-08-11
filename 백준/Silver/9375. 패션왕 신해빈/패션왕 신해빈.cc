#include <iostream>
#include <string>
#include <map>

using namespace std;

int T, n, ans = 1;
string tmp;
map<string, int> m;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    while(T--){
    	cin >> n;
    	while(n--){
    		cin >> tmp;
    		cin >> tmp;
    		
    		m[tmp]++;
		}
		for(auto it: m)	ans *= (it.second + 1);
		
		cout << ans - 1 << "\n";
		
		m.clear();
		ans = 1;
	}
	
	return 0;
}