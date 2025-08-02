#include <iostream>
#include <queue>

using namespace std;

int visited[65][65][65];
struct trio{
	int i, j, k;
};

const int dmg[6][3] = 
{{9, 3, 1},
{9, 1, 3},
{3, 9, 1},
{3, 1, 9},
{1, 9, 3},
{1, 3, 9}};

int bfs(int a, int b, int c){
	queue<trio> q;
	q.push({a, b, c});
	visited[a][b][c] = 1;
	while(!q.empty()){
		int x = q.front().i;
		int y = q.front().j;
		int z = q.front().k;
		q.pop();
		for(int i = 0; i < 6; i++){
			int nx = max(0, x - dmg[i][0]);
			int ny = max(0, y - dmg[i][1]);
			int nz = max(0, z - dmg[i][2]);
			
			if(nx == 0 && ny == 0 && nz == 0)
				return visited[x][y][z];
			if(visited[nx][ny][nz])
				continue;

			q.push({nx, ny, nz});
			visited[nx][ny][nz] = visited[x][y][z] + 1;
		}
	}
}

int main(){
	int N;
	int cd[3] = {0, 0, 0};
	
	cin >> N;
	
	for(int i = 0; i < N; i++) cin >> cd[i];
	
	cout << bfs(cd[0], cd[1], cd[2]);
	return 0;
}