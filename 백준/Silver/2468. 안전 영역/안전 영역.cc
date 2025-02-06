#include <bits/stdc++.h>

using namespace std;

int N, idx, ny, nx;
int cd[104][104];
int visited[104][104];
vector<int> h;
vector<int> ans;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int level){
    if(y < 0 || y >= N || x < 0 || x >= N) return;
    if(cd[y][x] <= h[idx] || visited[y][x]) return;
    visited[y][x]++;
    if(level == 0) ans[idx]++;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        dfs(ny, nx, level + 1);
    }
}

// void dfs(int y, int x){
// 	visited[y][x] = 1;
// 	for(int i = 0; i < 4; i++){
// 		ny = y + dy[i];
// 		nx = x + dx[i];
// 		if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
// 		if(cd[ny][nx] <= h[idx] || visited[ny][nx]) continue;
// 		dfs(ny, nx);
// 	}
// }

int main(){
	cin >> N;
	h.push_back(0);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cin >> cd[i][j];
			h.push_back(cd[i][j]);
		}
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());


	idx = 0;
	while(idx < h.size()){
	    ans.push_back(0);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				dfs(i, j, 0);
		memset(visited, 0, sizeof(visited));
		idx++;
	}
	cout << *max_element(ans.begin(), ans.end());
	
	return 0;
}