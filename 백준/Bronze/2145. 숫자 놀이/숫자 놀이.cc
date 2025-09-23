#include <iostream>
using namespace std;

void solve(int x) {
	while (x > 9) {
		int tmp = 0;
		while (x) {
			tmp += x % 10;
			x /= 10;
		}
		x = tmp;
	}
	cout << x << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N; cin >> N;
	while (N) {
		solve(N);
		cin >> N;
	}
}