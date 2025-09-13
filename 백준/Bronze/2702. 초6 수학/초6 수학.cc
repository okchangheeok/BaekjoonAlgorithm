#include <iostream>

using namespace std;

int T, a, b, MIN, MAX, X, Y;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> T;
	
	while(T--){
		cin >> a >> b;
		MAX = max(a, b);
		while(MAX % a || MAX % b) MAX++;
		cout << MAX << " ";
		
		MIN = min(a, b);
		while(a % MIN || b % MIN) MIN--;
		cout << MIN << "\n";
	}
	
    return 0;
}