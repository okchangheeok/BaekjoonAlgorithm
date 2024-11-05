#include <bits/stdc++.h>

using namespace std;

int M, N, K, y_1, x_1, y_2, x_2, ans;
int cd[104][104];
int visited[104][104];
int area[2504];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
	visited[y][x] = 1;
	area[ans]++;
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
		if(!cd[ny][nx] || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main(){
	fill(&cd[0][0], &cd[0][0] + 104 * 104, 1);
	cin >> M >> N >> K;
	
	while(K--){
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for(int i = y_1; i < y_2; i++)
			for(int j = x_1; j < x_2; j++)
				cd[i][j] = 0;
	}
	
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			if(cd[i][j] && !visited[i][j]){
				dfs(i, j);
				ans++;
			}
			
	sort(area, area + ans);
	
	cout << ans << "\n";
	for(int i = 0; i < ans; i++)
		cout << area[i] << " ";
	
	return 0;
}