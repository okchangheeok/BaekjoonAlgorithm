#include <bits/stdc++.h>

using namespace std;

int t[100], A, B, C, t1, t2, ans;

int main(){
	cin >> A >> B >> C;
	B *= 2;
	C *= 3;
	//visited를 넣어도 되겠 
	for(int i = 0; i < 3; i++){
		cin >> t1 >> t2;
		for(int j = t1; j < t2; j++)
			t[j]++;
	}
	
	for(int i = 0; i < 100; i++){
		if(t[i] == 1)
			ans += A;
		else if(t[i] == 2)
			ans += B;
		else if(t[i] == 3)
			ans += C; 
	}

	cout << ans; 
	
	return 0;
}