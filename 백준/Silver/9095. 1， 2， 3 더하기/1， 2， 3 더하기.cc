#include <bits/stdc++.h>

using namespace std;

int T, n;

int ans(int n){
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else if(n == 3)
		return 4;
	else if(n == 4)
		return 7;
	else
		return 2 * ans(n - 1) - ans(n - 4);
}

int main(){
	cin >> T;
	while(T--){
		cin >> n;
		cout << ans(n) << "\n";
	}
	return 0;
}