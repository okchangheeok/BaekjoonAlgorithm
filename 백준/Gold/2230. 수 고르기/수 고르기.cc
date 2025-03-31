#include <bits/stdc++.h>
using namespace std; 

int N, M, l, r, ans = 2000000000;
int arr[100005];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort(arr, arr + N);
	while(l < N){
		if(arr[r] - arr[l] < M)
			r++;
		else if(M < arr[r] - arr[l]){
			ans = min(ans, arr[r] - arr[l]);
			l++;
		}
		else{
			ans = M;
			break;
		}
	}
	cout << ans;
	
	return 0;
}