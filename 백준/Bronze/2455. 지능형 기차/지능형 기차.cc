#include <iostream>
using namespace std;

int tmp, ppl, ans;

int main(){
	for(int i = 0; i < 3; i++){
		cin >> tmp;
		ppl -= tmp;
		
		cin >> tmp;
		ppl += tmp;
		ans = max(ans, ppl);
	}
	cout << ans;
	return 0;
}