#include <iostream>
using namespace std;

int tmp_score, tmp_ans, ans, winner;

int main(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 4; j++){
			cin >> tmp_score;
			tmp_ans += tmp_score;
		}
		if(tmp_ans > ans){
			winner = i;
			ans = tmp_ans;
		}
		tmp_ans = 0;
	}
	
	cout << winner + 1 << " " << ans;
	
	return 0;
}