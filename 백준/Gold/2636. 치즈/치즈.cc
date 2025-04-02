#include <bits/stdc++.h>
using namespace std; 

int Y, X, ny, nx, T, melt, last_melt;
int cd[105][105];
int visited[105][105];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x){
	visited[y][x] = 1;
	
	for(int i = 0; i < 4; i++){
		ny = y + dy[i];
		nx = x + dx[i];
		if(ny < 0 || Y <= ny || nx < 0 || X <= nx) continue;
		if(cd[ny][nx] == 1){
			melt++;
			cd[ny][nx] = 0;
			visited[ny][nx] = 1;
		}
		if(visited[ny][nx] == 1) continue;
		dfs(ny, nx);
	}
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> Y >> X;
	for(int i = 0; i < Y; i++)
		for(int j = 0; j < X; j++)
			cin >> cd[i][j];
	
	

	while(1){
		dfs(0, 0);
		if(melt == 0)
			break;
		
		T++;
		last_melt = melt;
		melt = 0;
		
		memset(visited, 0, sizeof(visited));
	} 
	
	cout << T << "\n" << last_melt;
	
	return 0;
}