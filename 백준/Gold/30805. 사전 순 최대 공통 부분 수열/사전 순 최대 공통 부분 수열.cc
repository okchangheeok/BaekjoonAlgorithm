#include <bits/stdc++.h>
using namespace std; 

int N, M, tmp;
vector<int> A;
vector<int> B;
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	// A 입력 
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> tmp;
		A.push_back(tmp);
	}
	// B 입력 
	cin >> M;
	for(int i = 0; i < M; i++){
		cin >> tmp;
		B.push_back(tmp);
	}
	
	
	while(A.size() && B.size()){
		//B와 겹치는 것만 A에 남기기
		for(auto it = A.begin(); it != A.end();){
			if(find(B.begin(), B.end(), *it) == B.end())
				A.erase(it);
			else it++;
		}
		//A와 겹치는 것만 B에 남기기
		for(auto it = B.begin(); it != B.end();){
			if(find(A.begin(), A.end(), *it) == A.end())
				B.erase(it);
			else it++;
		}
		//size가 0일때 max_element함수 오류 방지
		if(A.size()){ 
			//겹치는 부분 중 최댓값을 ans에 push
			ans.push_back(*max_element(A.begin(), A.end()));
			//A와 B 모두 최댓값 포함 이전 부분 erase
			A.erase(A.begin(), max_element(A.begin(), A.end()) + 1);
			B.erase(B.begin(), max_element(B.begin(), B.end()) + 1);
		}
	}
	cout << ans.size() << "\n";
	for(auto i: ans) cout << i << " ";
	
	return 0;
}