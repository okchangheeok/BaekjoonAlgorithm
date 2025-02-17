#include <bits/stdc++.h>

using namespace std;

int N, M, V, f, s, qf;
vector<vector<int>> v(1005);
int visited[1005];
queue<int> q;

void dfs(int i){
	visited[i] = 1;
	cout << i << " ";
	for(int it: v[i])
		if(visited[it] == 0)
			dfs(it);
}

int main()
{
    cin >> N >> M >> V;
    for(int i = 0; i < M; i++){
    	cin >> f >> s;
		v[f].push_back(s);
		v[s].push_back(f);
	}
	for(int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());
	
	dfs(V);
	cout << "\n";
	memset(visited, 0, sizeof(visited));
	
	q.push(V);
	visited[V] = 1;
	while(q.size()){
		qf = q.front(); q.pop();
		
		cout << qf << " ";
		
		for(int it: v[qf])
			if(visited[it] == 0){
				visited[it] = 1;
				q.push(it);
			}
	}
	
    return 0;
}