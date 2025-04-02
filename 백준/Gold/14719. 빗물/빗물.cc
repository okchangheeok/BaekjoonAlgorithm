#include <bits/stdc++.h>
using namespace std; 

int H, W, tmp, ans;
vector<int> v;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> H >> W;
	for(int i = 0; i < W; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
		
	
	//fronthalf count
	auto top = max_element(v.begin(), v.end());
	if(v.begin() < top){
		while(1){
			auto next_top = max_element(v.begin(), top);
			for(auto it = top - 1; next_top < it; it--)
				ans += *next_top - *it;
			if(next_top == v.begin())
				break;
			top = next_top;
		}
	}
	//backhalf count
	top = max_element(v.begin(), v.end());
	if(top < v.end() - 1){
		while(1){
			auto next_top = max_element(top + 1, v.end());
			for(auto it = top + 1; it < next_top; it++)
				ans += *next_top - *it;
			if(next_top == v.end() - 1)
				break;
			top = next_top;
		}
	}
	cout << ans;
 
	return 0;
}