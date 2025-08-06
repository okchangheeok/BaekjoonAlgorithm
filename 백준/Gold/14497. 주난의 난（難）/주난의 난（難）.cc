#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, M, x1, y1, x2, y2, ans;
char cd[305][305];
int visited[305][305];

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

bool bfs(){
	queue<pair<int, int>> q;
	q.push({y1, x1});
	visited[y1][x1] = 1;
	while(!q.empty()){
		int y, x;
		tie(y, x) = q.front(); q.pop();
		
		for(int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
			if(visited[ny][nx]) continue;
			
			if(cd[ny][nx] == '1')		cd[ny][nx] = '0';
			else if(cd[ny][nx] == '0')	q.push({ny, nx});
			else						return 1;
			
			visited[ny][nx] = visited[y][x];
		}
	}

	return 0;
}

int main(){
	cin >> N >> M;
	cin >> y1 >> x1 >> y2 >> x2;
	y1 -= 1; x1 -= 1; y2 -= 1; x2 -= 1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> cd[i][j];
		}
	}
	
	while(bfs() == 0) {
		ans++;
		memset(visited, 0, sizeof(visited));
	}
	cout << ans + 1;
	
	return 0;
}