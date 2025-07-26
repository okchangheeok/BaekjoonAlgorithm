#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int cd[10][10];
int visited[10][10];
vector<pair<int, int>> zero_loc;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs(int CD[10][10], int y, int x){
	int ans = 1;
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
		if(visited[ny][nx] == 1) continue;
		if(CD[ny][nx] == 0){
			CD[ny][nx] = 2;
			dfs(CD, ny, nx);
		}
	}
}

int cal(int base[10][10]) {
    int C[10][10];
    memcpy(C, base, sizeof(C));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(C[i][j] == 2){
                dfs(C, i, j);
            }
        }
    }

    int safe = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(C[i][j] == 0) safe++;
        }
    }

    return safe;
}

int threeWalls(int cd[10][10]){
	int ans = 0;
	for(int i = 0; i < zero_loc.size(); i++){
		cd[zero_loc[i].first][zero_loc[i].second] = 1;
		for(int j = i + 1; j < zero_loc.size(); j++){
			cd[zero_loc[j].first][zero_loc[j].second] = 1;
			for(int k = j + 1; k < zero_loc.size(); k++){
				cd[zero_loc[k].first][zero_loc[k].second] = 1;
				ans = max(ans, cal(cd));
				memset(visited, 0, sizeof(visited));
				cd[zero_loc[k].first][zero_loc[k].second] = 0;
			}
			cd[zero_loc[j].first][zero_loc[j].second] = 0;
		}
		cd[zero_loc[i].first][zero_loc[i].second] = 0;
	}
	
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
    	for(int j = 0; j < M; j++){
    		cin >> cd[i][j];
    		if		(cd[i][j] == 0) zero_loc.push_back({i, j});
		}
	}
	
	cout << threeWalls(cd);
	
	return 0;
}