#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

long long N, C, tmp;

map<long long, int> m;
map<long long, int> loc;

vector<pair<long long, int>> ans;

bool compare(const pair<long long, int> a, const pair<long long, int> b){
	if(a.second != b.second) return a.second > b.second;
	else return loc[a.first] < loc[b.first];
}

int main()
{
	cin >> N >> C;
	for(int i = 1; i <= N; i++){
		cin >> tmp;
		m[tmp]++;
		if(loc.find(tmp) == loc.end()) loc[tmp] = i;
	}
	
	for(auto it: m)
		ans.push_back({it.first, it.second});
	
	sort(ans.begin(), ans.end(), compare);
	
	for(auto it: ans)
		for(int i = 0; i < it.second; i++)
			cout << it.first << " ";
	
    return 0;
}