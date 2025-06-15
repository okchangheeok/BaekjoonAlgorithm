#include <bits/stdc++.h>

using namespace std;

int M, N, ans, ans_flag;
int cd[1005][1005];
int visited[1005][1005];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> M >> N;
    
    for(int i = 0; i < N; i++)
    	for(int j = 0; j < M; j++){
    		cin >> cd[i][j];
    		if(cd[i][j] == 1) q.push({i, j});
    	}
    
    while(!q.empty()){
    	int y, x;
    	tie(y, x) = q.front(); q.pop();
    	for(int i = 0; i< 4; i++){
    		int ny = y + dy[i];
    		int nx = x + dx[i];
    		
    		if(ny < 0 || N <= ny || nx < 0 || M <= nx) continue;
    		if(cd[ny][nx] != 0) continue;
    		
    		q.push({ny, nx});
    		cd[ny][nx] = 1;
    		visited[ny][nx] = visited[y][x] + 1;
    		
    		ans = visited[ny][nx];
		}
	}
	
	for(int i = 0; i < N; i++){
    	for(int j = 0; j < M; j++)
    		if(cd[i][j] == 0){
    		    ans_flag = 1;
    		    break;
    		}
    	if(ans_flag) break;
	}
    
    if(ans_flag)    cout << -1;
    else            cout << ans;
    
	return 0;
}
