#include <bits/stdc++.h>

using namespace std;

int N, K;
int w, v, ans[100005];
vector<pair<int, int>> vec;

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++){
    	cin >> w >> v;
    	vec.push_back({w, v});
    }
	
	sort(vec.begin(), vec.end());
	
	for(auto it: vec)
		for(int j = K; it.first <= j; j--)
    		ans[j] = max(ans[j], ans[j - it.first] + it.second);
	cout << ans[K];
}