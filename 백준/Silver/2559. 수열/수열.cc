#include <iostream>

using namespace std;

int N, K, stdd, ans;
int cd[100005];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> cd[i];
	
	for(int i = 0; i < K; i++)
		stdd += cd[i];
	
	ans = stdd;
	for(int i = K; i < N; i++){
		stdd += cd[i];
		stdd -= cd[i - K];
		ans = max(ans, stdd);
	}
	
	cout << ans;
	
	return 0;
}