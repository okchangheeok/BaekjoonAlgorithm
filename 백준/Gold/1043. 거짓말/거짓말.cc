#include <bits/stdc++.h>
using namespace std;

int N, M, T, tmp, pp, ps, flag, ans, tmp_ans;
set<int> Tmen;
vector<vector<int>> Pmen(55);
vector<int> banned_P;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> T;
	ans = M;
	
	for(int i = 0; i < T; i++){
		cin >> tmp;
		Tmen.insert(tmp);
	}
	for(int i = 0; i < M; i++){
		cin >> pp;
		for(int j = 0; j < pp; j++){
			cin >> ps;
			Pmen[i].push_back(ps);
		}
	}
	while(1){
		tmp_ans = ans;
		for(int i = 0; i < M; i++){
			if(find(banned_P.begin(), banned_P.end(), i) != banned_P.end()) continue;
			for(int j = 0; j < Pmen[i].size(); j++){
				if(find(Tmen.begin(), Tmen.end(), Pmen[i][j]) != Tmen.end()){
					//해당 파티 밴 
					banned_P.push_back(i);
					//답 1 빼기
					ans--;
					//파티 사람 Tmen에 추가
					for(int it: Pmen[i]) Tmen.insert(it);
					break;
				}
			}
		}
		if(tmp_ans == ans) break;
	}
	
	cout << ans;
	return 0;
}