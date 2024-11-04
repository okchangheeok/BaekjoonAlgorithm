#include <bits/stdc++.h>

using namespace std;

int N, M, y, x, ny, nx;
int cd[104][104];
string str[104];
int visited[104][104];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> str[i];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++){
			cd[i][j] = (int)(str[i][j] - '0');
		}
	
	q.push({0, 0});
	visited[0][0] = 1;
	while(q.size()){
		tie(y, x) = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			ny = y + dy[i];
			nx = x + dx[i];
			if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if(!cd[ny][nx] || visited[ny][nx]) continue;
			q.push({ny, nx});
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	
	cout << visited[N-1][M-1];
	return 0;
}