#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> x >> y >> w >> h;
	
	cout << min({w - x, x, h - y, y});
	
    return 0;
}