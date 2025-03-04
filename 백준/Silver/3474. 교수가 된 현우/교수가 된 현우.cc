#include <bits/stdc++.h>

using namespace std;

long long N;
int tmp, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N;
	while(N--){
		cin >> tmp;
		while(5 <= tmp)	ans += (tmp /= 5);
		cout << ans << "\n";
		ans = 0;
	}
    return 0;
}