#include <iostream>

using namespace std;

long long A, B, C;

long long go(long long b){
	if(b == 1) return A % C;
	
	long long ret;
	
	ret = go(b/2);
	ret = (ret * ret) % C;
	
	if(b % 2 == 1) ret = (ret * A) % C;
	
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> A >> B >> C;
    
    cout << go(B);
    
	return 0;
}