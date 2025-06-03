#include <bits/stdc++.h>
using namespace std;

int N, team, score1, score2, now_time, prv_time, sec1, sec2;
bool cnt_flag;
string time_str;

void print_ans(int a){
	if(a / 60 < 10) cout << "0";
	cout << a / 60 << ":";
	if(a % 60 < 10) cout << "0";
	cout << a % 60 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
    	cin >> team >> time_str;
    	if(team == 1)	score1++;
    	else			score2++;
    	if(abs(score1 - score2) == 1 && cnt_flag == 0){
    		cnt_flag = 1;
    		prv_time = 0;
			prv_time += 60 * stoi(time_str.substr(0, 2));
			prv_time += stoi(time_str.substr(3, 2));
		}
    	else if(score1 == score2 && cnt_flag == 1){
    		cnt_flag = 0;
    		now_time = 0;
    		now_time += 60 * stoi(time_str.substr(0, 2));
			now_time += stoi(time_str.substr(3, 2));
			
    		if(team == 1)		sec2 += now_time - prv_time;
    		else if(team == 2)	sec1 += now_time - prv_time;
    	}
	}
	if(cnt_flag){
		now_time = 60 * 48;
		if(score1 > score2)			sec1 += now_time - prv_time;
		else if(score1 < score2)	sec2 += now_time - prv_time;
    }
	
	
	print_ans(sec1); print_ans(sec2);
	
	return 0;
}