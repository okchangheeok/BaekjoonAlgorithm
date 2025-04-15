#include <bits/stdc++.h>
using namespace std;

int N, tmp;
vector<int> v;

bool cmp(const int &a, const int &b){
	if(abs(a) == abs(b))
		return a < b;
	else
		return abs(a) < abs(b);
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N;
	while(N--){
		cin >> tmp;
		if(tmp == 0){
			if(v.size()){
				auto ans_ad = min_element(v.begin(), v.end(), cmp);
				cout << *ans_ad << "\n";
				v.erase(ans_ad);
			}
			else cout << "0" << "\n";
		}
		else v.push_back(tmp);
	}
	return 0;
}