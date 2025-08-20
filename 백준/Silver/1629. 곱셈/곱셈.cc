#include <iostream>

using namespace std;

long long A, B, C;

long long go(long long b){
	if(b == 1) return A % C;
	
	long long ret;
	ret = go(b / 2);
	ret = ret * ret % C;
	
	if(b % 2 == 1) ret = ret * A % C;
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;
	
	cout << go(B);

	return 0;
}