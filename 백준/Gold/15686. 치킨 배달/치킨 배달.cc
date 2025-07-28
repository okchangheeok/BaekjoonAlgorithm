#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> ans_list;
int cd[55][55];
vector<pair<int, int>> house_loc;
vector<pair<int, int>> chick_loc;
vector<vector<int>> dist(15);
vector<int> picked_house;

void calculate(){
	int tmp_ans = 0;
	int min_dist[105];
	fill(min_dist, min_dist + 105, 105);
	
	for(int i: picked_house)
		for(int j = 0; j < house_loc.size(); j++)
			min_dist[j] = min(min_dist[j], dist[i][j]);
	
	for(int i = 0; i < house_loc.size(); i++)
		tmp_ans += min_dist[i];
	ans_list.push_back(tmp_ans);
}

void combi(int level){
	if(picked_house.size() == M){
		calculate();
		return;
	}
	for(int i = level; i < chick_loc.size(); i++){
		picked_house.push_back(i);
		combi(i + 1);
		picked_house.pop_back();
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> cd[i][j];
			if(cd[i][j] == 1)		house_loc.push_back({i, j});
			else if(cd[i][j] == 2)	chick_loc.push_back({i, j});
		}
	}
	
	for(int i = 0; i < chick_loc.size(); i++){
		for(auto j: house_loc){
			int tmp_dist = abs(chick_loc[i].first - j.first) + abs(chick_loc[i].second - j.second);
			dist[i].push_back(tmp_dist);
		}
	}
	
	combi(0);
	
	
	cout << *min_element(ans_list.begin(), ans_list.end());
	
	return 0;
}