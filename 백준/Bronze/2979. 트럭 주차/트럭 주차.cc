#include <bits/stdc++.h>

using namespace std;

int t[104], A, B, C, t1, t2, ans;

int main(){
	cin >> A >> B >> C;
	
    for(int i = 0; i < 3; i++){
		cin >> t1 >> t2;
		for(int j = t1; j < t2; j++)
			t[j]++;
	}
	
	for(int i = 0; i < 100; i++){
        if(t[i] == 1)
			ans += A;
		else if(t[i] == 2)
			ans += B * 2;
		else if(t[i] == 3)
			ans += C * 3; 
	}

	cout << ans; 
	
	return 0;
}