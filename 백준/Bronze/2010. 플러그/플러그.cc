#include <iostream>

using namespace std;

int N, tmp, ans = 1;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N;
	while(N--){
		cin >> tmp;
		ans += tmp;
		ans -= 1;
	}
	
	cout << ans;

    return 0;
}