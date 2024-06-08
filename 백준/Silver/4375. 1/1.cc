#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, rmn, sum, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    while(cin >> n){
    	rmn = 1 % n;
    	sum = rmn;
    	ans = 1;
    	while(1){
    		if(sum % n == 0)
    			break;
    		rmn = (10 * rmn) % n;
    		sum += rmn;
    		sum %= n;
    		ans++;
		}
		cout << ans << '\n';
    }
	return 0;
}

