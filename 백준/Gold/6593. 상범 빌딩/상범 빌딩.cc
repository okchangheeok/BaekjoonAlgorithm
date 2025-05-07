#include <bits/stdc++.h>
using namespace std;

int L, R, C, sl, a, b, c, flag;

char cd[35][35][35];
int visited[35][35][35];
int dz[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {1, -1, 0, 0, 0, 0};

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	while(1){
		cin >> L >> R >> C;
		if(L == 0 && R == 0 && C == 0) break;
		
		queue<tuple<int, int, int>> q;
		
		for(int i = 0; i < L; i++){
			for(int j = 0; j < R; j++){
				for(int k = 0; k < C; k++){
					cin >> cd[i][j][k];
					if(cd[i][j][k] == 'S'){
						q.push(make_tuple(i, j, k));
					}
				}
			}
		}
		while(q.size()){
			tie(a, b, c) = q.front(); q.pop();
			if(cd[a][b][c] == 'E'){
				flag = 1;
				break;
			}
			for(int i = 0; i < 6; i++){
				int z = a + dz[i];
				int y = b + dy[i];
				int x = c + dx[i];
				if(z < 0 || L <= z) continue;
				if(y < 0 || R <= y) continue;
				if(x < 0 || C <= x) continue;
				if(cd[z][y][x] == '#') continue;
				if(visited[z][y][x] != 0) continue;
				q.push(make_tuple(z, y, x));
				visited[z][y][x] = visited[a][b][c] + 1;
			}
		}
		
		if(flag) cout << "Escaped in " << visited[a][b][c] << " minute(s).\n";
		else cout << "Trapped!\n";
		
		flag = 0;
		memset(cd, 0, sizeof(cd));
		memset(visited, 0, sizeof(visited));
	}
	
	return 0;
}