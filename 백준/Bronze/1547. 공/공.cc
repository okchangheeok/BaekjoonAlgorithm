#include <iostream>

using namespace std;

int M, X, Y, ans = 1;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> M;
	
	while(M--){
		cin >> X >> Y;
		if(X == ans) ans = Y;
		else if(Y == ans) ans = X;
	}
	
	cout << ans;
	
    return 0;
}