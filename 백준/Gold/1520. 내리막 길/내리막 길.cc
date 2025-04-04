#include <bits/stdc++.h>
using namespace std; 

int M, N, H;
int cd[505][505];
int dp[505][505];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
	if(y == M - 1 && x == N - 1){
		dp[y][x] = 1;
		return;
	}
	if(dp[y][x] != -1) return;
	if(dp[y][x] == -1) dp[y][x] = 0;
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || M <= ny || nx < 0 || N <= nx) continue;
		if(cd[y][x] <= cd[ny][nx]) continue;
//		cout << "dp1\n";
//		cout << ny << " : " << nx << "\n";
//		for(int i = 0; i < M; i++){
//			for(int j = 0; j < N; j++)
//				cout << dp[i][j] << " ";
//			cout << "\n";
//		}
		dfs(ny, nx);
		dp[y][x] += dp[ny][nx];
//		cout << "dp0\n";
//		cout << ny << " : " << nx << "\n";
//		for(int i = 0; i < M; i++){
//			for(int j = 0; j < N; j++)
//				cout << dp[i][j] << " ";
//			cout << "\n";
//		}
	}
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> M >> N;
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			cin >> cd[i][j];
	
	dfs(0, 0);
	
	cout << dp[0][0];
	
	return 0;
}