#include <bits/stdc++.h>

using namespace std;

int tc, N, M, K, ny, nx, ans;
int cd[54][54];
int visited[54][54];
int ycd[2504], xcd[2504];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
	if(y < 0 || y >= N || x < 0 || x >= M) return;
	if(!cd[y][x] || visited[y][x]) return;
	visited[y][x] = 1;
	for(int i = 0; i < 4; i++){
		ny = y + dy[i];
		nx = x + dx[i];
		dfs(ny, nx);
	}
}

int main(){
	cin >> tc;
	while(tc--){
		cin >> M >> N >> K;
		for(int i = 0; i < K; i++){
			cin >> xcd[i] >> ycd[i];
			cd[ycd[i]][xcd[i]]++;
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				if(cd[i][j] && !visited[i][j]){
					dfs(i, j);
					ans++;
				}
		cout << ans << "\n";
		
		memset(xcd, 0, sizeof(xcd));
		memset(ycd, 0, sizeof(ycd));
		memset(cd, 0, sizeof(cd));
		memset(visited, 0, sizeof(visited));
		ans = 0;
	}
	return 0;
}