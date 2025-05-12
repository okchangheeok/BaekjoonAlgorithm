#include <bits/stdc++.h>
using namespace std;

int N, A, B, cur, MIN = 100;
vector<vector<int>> v(55);
int visited[55];
vector<vector<int>> score(55);
int score_max[55];
queue<int> q;
vector<int> candi;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N;
	while(1){
		cin >> A >> B;
		if(A == -1 && B == -1) break;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	
	for(int i = 1; i <= N; i++){
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			cur = q.front(); q.pop();
			for(int it: v[cur]){
				if(visited[it] == 0){
					q.push(it);
					visited[it] = visited[cur] + 1;
					if(i < it){
						score[i].push_back(visited[it]);
						score[it].push_back(visited[it]);
					}
				}
			}
		}
		memset(visited, 0, sizeof(visited));
	}
	
	for(int i = 1; i <= N; i++){
		score_max[i] = *max_element(score[i].begin(), score[i].end());
		if(score_max[i] <= MIN){
			if(score_max[i] < MIN){
				candi.clear();
				MIN = score_max[i];
			}
			candi.push_back(i);
		}
	}
	
	cout << MIN << " " << candi.size() << "\n";
	for(int i: candi) cout << i << " ";
	
	return 0;
}