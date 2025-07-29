#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, M, ans, y, x;
char cd[55][55];
int visited[55][55];
vector<pair<int, int>> land;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
    	for(int j = 0; j < M; j++){
    		cin >> cd[i][j];
    		if(cd[i][j] == 'L') land.push_back({i, j});
		}
	}
	while(!land.empty()){
		queue<pair<int, int>> q;
		q.push(land.back()); land.pop_back();
		memset(visited, -1, sizeof(visited));
		tie(y, x) = q.front();
		visited[y][x] = 0;
		while(!q.empty()){
			tie(y, x) = q.front(); q.pop();
			for(int i = 0; i < 4; i++){
				int ny = y + dy[i];
				int nx = x + dx[i];
				
				if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
				if(cd[ny][nx] == 'W') continue;
				if(0 <= visited[ny][nx]) continue;
				q.push({ny, nx});
				visited[ny][nx] = visited[y][x] + 1;
				ans = max(ans, visited[ny][nx]);
			}
		}
	}
	
	cout << ans;

    return 0;
}