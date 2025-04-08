#include <bits/stdc++.h>
using namespace std; 

int N, tmp, B, ans;
int par[55];
vector<vector<int>> tree(55);

void dfs(int n){
	if(tree[n].size() == 0){
		ans++;
		return;
	}
	
	for(int i: tree[n])	dfs(i);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> par[i];
		if(par[i] == -1) par[i] = 51;
		tree[par[i]].push_back(i);
	}
	
	cin >> B;
	tree[par[B]].erase(find(tree[par[B]].begin(), tree[par[B]].end(), B));
	
	for(int i: tree[51]) dfs(i);
	
	cout << ans;
	
	return 0;
}