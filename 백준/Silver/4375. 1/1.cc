#include <iostream>

using namespace std;

int n, D = 1, tmp, ans;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	
	while(cin >> n){
		while(1){
			D %= n;
			ans++;
			if(D == 0) break;
			else D = D * 10 + 1;
		}
		cout << ans << "\n";
		
		D = 1;
		ans = 0;
	}
	
	return 0;
}