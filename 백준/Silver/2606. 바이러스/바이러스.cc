#include <bits/stdc++.h>

using namespace std;

int N, M, a, b, ans;
vector<vector<int>> v(105);
bool visited[105];

void cnt(int k){
	visited[k] = 1;
	for(int i = 0; i < v[k].size(); i++)
		if(visited[v[k][i]] == 0){
			ans++;
			cnt(v[k][i]);
		}
}

int main()
{
	cin >> N >> M;
	while(M--){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cnt(1);
	
	cout << ans;
    return 0;
}