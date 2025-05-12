#include <bits/stdc++.h>
using namespace std;

string A, B;
int Alen, Blen;
int dp[1005][1005];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> A >> B;
	Alen = A.size();
	Blen = B.size();
	
	//뒤 연산 부분에서 인덱스 정리를 위해 앞에 한글자 추가
	A = "0" + A;
	B = "0" + B;

	//연산. 이전 값 참조 시 에러 방지 위해 인덱스 1부터 진행
	for(int i = 1; i <= Alen; i++){
		for(int j = 1; j <= Blen; j++){
			//같을 시 대각선 참조
			if(A[i] == B[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			//다를 시 왼쪽과 위 중 큰 것 참조
			else
			    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
// 	//디버그 
// 	for(int i = 1; i <= Alen; i++){
// 		for(int j = 1; j <= Blen; j++){
// 			cout << dp[i][j] << " ";
// 		}
// 		cout << "\n";
// 	}

	cout << dp[Alen][Blen];
	
	return 0;
}
