#include <iostream>

using namespace std;

int N, M, J, cur = 1, tmp, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> J;
	
	while(J--){
		cin >> tmp;
		
		if(cur <= tmp && tmp < cur + M) continue;
		else if(tmp < cur){
			ans += cur - tmp;
			cur = tmp;
		}
		else{
			ans += tmp - (cur + M - 1);
			cur = tmp - M + 1;
		}
	}
	
	cout << ans;

	return 0;
}