#include <bits/stdc++.h>
using namespace std; 

int M, N, s_len, cnt_child;
int snack[1000005];

int BS(){
	int left = 0;
	int right = snack[0];
	
	while(1 < right - left){
		int mid = left + (right - left) / 2;
		if(mid == 0) break;
		for(int i = 0; i < N; i++){
			if(snack[i] < mid) break;
			cnt_child += snack[i] / mid;
			if(M <= cnt_child) break;
		}
		if(M <= cnt_child) left = mid;
		else right = mid - 1;
		cnt_child = 0;
	}
	if(right == 0) return left;
	for(int i = 0; i < N; i++){
		if(snack[i] < right) break;
		cnt_child += snack[i] / right;
		if(M <= cnt_child) break;
	}
	if(M <= cnt_child) left = right;
	
	return left;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> M >> N;
	for(int i = 0; i < N; i++)
		cin >> snack[i];
	sort(snack, snack + N, greater<int>());

	cout << BS();
	return 0;
}