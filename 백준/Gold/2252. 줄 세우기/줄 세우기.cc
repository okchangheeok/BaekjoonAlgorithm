#include <bits/stdc++.h>
using namespace std; 

int N, M, A, B, A_lev, B_lev, lev_dif;
vector<vector<int>> tree(33000);
int level[33000];
int upper[33000];
queue<int> q;
vector<vector<int>> ans_level(33000); 

int ch_lev(int node){
	if(upper[node] == 0) return 0;
	return ch_lev(upper[node]) + 1;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) tree[0].push_back(i);
	for(int i = 0; i < M; i++){
		cin >> A >> B;
		lev_dif = ch_lev(A) - ch_lev(B);
		//level이 B가 더 높거나 같다면 
		if(0 <= lev_dif){
			//tree graph 갱신
			tree[A].push_back(B);
			//기존 upper에서 자식노드B 제거
			auto Bloc = find(tree[upper[B]].begin(), tree[upper[B]].end(), B);
			tree[upper[B]].erase(Bloc);
			//upper 갱신 
			upper[B] = A;
		}
	}
    
	//bfs 방식으로 출력 
	q.push(0);
	while(q.size()){
		int cur = q.front();
		for(int j: tree[cur]){
			q.push(j);
			cout << j << " ";
		}
		q.pop();
	}

	return 0;
}