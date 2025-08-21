#include <iostream>
#include <string>

using namespace std;

int N;
char cd[70][70];

const int dy[] = {-1, -1, 0, 0};
const int dx[] = {-1, 0, -1, 0};

string dfs(int y, int x, int n){
	string ret;
	
	if(n == 1) {
		ret += cd[y][x];
		return ret;
	}
	for(int i = 0; i < 4; i++){
		int ny = y + dy[i] * n / 2;
		int nx = x + dx[i] * n / 2;
		ret += dfs(ny, nx, n / 2);
	}
	if(ret == "1111")		ret = "1";
	else if(ret == "0000")	ret = "0";
	else					ret = "(" + ret + ")";
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> cd[i][j];
	
	cout << dfs(N, N, N);

	return 0;
}