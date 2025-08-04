#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[100005];
int rev_path[100005];

void bfs(){
	queue<int> q;
	q.push(N);
	visited[N] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int nx: {x - 1, x + 1, x * 2}){
			if(nx < 0 || 100000 < nx) continue;
			if(visited[nx]) continue;
			
			q.push(nx);
			visited[nx] = visited[x] + 1;
			rev_path[nx] = x;
			
			if(nx == K)	return;
		}
	}
	return;
}

int main(){
	cin >> N >> K;
	rev_path[N] = -1;
	bfs();
	cout << visited[K] - 1 << "\n";
	
	vector<int> path;
	
	for(int i = K; i != -1; i = rev_path[i])
		path.push_back(i);

	for(int i = path.size() - 1; 0 <= i; i--)
		cout << path[i] << " ";
	
	return 0;
}