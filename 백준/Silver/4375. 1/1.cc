#include <iostream>

using namespace std;

int n, D = 1, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
  	
	while(cin >> n){
  		while(D){
  			D %= n;
  			ans++;
  			
  			if(D == 0)	break;
  			else		D = D * 10 + 1;
		}
		
		cout << ans << "\n";
		
  		D = 1; ans = 0;
	}
  	
	return 0;
}