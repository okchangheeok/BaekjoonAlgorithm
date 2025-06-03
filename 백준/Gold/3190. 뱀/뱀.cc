#include <bits/stdc++.h>
using namespace std;

int N, K, L, X, dir_idx, head_y, head_x, end_flag, ans;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
char C;
int cd[105][105];//[1][1] ~ [N][N]
queue<pair<int, int>> body;
map<int, char> dir;

void move(){
	ans++;
	head_y += dy[dir_idx]; head_x += dx[dir_idx];
    
	if(cd[head_y][head_x] == 1){
		end_flag = 1;
		return;
	}
	else if(cd[head_y][head_x] == 0){
		int tail_y; int tail_x;
		tie(tail_y, tail_x) = body.front(); body.pop();
		cd[tail_y][tail_x] = 0;
	}
	cd[head_y][head_x] = 1;
	body.push({head_y, head_x});
	
	if(dir.find(ans) != dir.end()){
		if(dir[ans] == 'L')			dir_idx--;
		else if(dir[ans] == 'D')	dir_idx++;
		
		dir_idx = (dir_idx + 4) % 4;
	}
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    head_y = 1; head_x = 1;
    cd[head_y][head_x] = 1;
    body.push({head_y, head_x});
    
    cin >> N;
    for(int i = 0; i <= N + 1; i++)
    	for(int j = 0; j <= N + 1; j++)
    		if(i == 0 || i == N + 1 || j == 0 || j == N + 1)
    			cd[i][j] = 1;

	cin >> K;
    while(K--){
    	int apple_y, apple_x;
    	cin >> apple_y >> apple_x;
    	cd[apple_y][apple_x] = 2;
	}
	
	cin >> L;
	while(L--){
		cin >> X >> C;
		dir[X] = C;
	}
	
	while(end_flag == 0){
		move();
	}
	cout << ans;
	return 0;
}