#include <iostream>

using namespace std;

int N, A, B;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N >> A >> B;
	cout << min(N, (A / 2 + B));
	
    return 0;
}