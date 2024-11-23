#include <bits/stdc++.h>

using namespace std;

int h[13], sum, rem, x1, x2;

int main(){
	for(int i = 0; i < 9; i++){
		cin >> h[i];
		sum += h[i];
	}
	sort(h, h + 9);
	rem = sum - 100;
	
	for(x1 = 0; x1 < 8; x1++){
		for(x2 = x1 + 1; x2 < 9; x2++)
			if(h[x1] + h[x2] == rem)
				break;
		if(h[x1] + h[x2] == rem)
			break;
	}
	for(int i = 0; i < 9; i++){
		if(i == x1 || i == x2) continue;
		cout << h[i] << "\n";
	}
	
	return 0;
}