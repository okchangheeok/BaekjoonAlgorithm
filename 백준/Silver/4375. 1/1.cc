#include <iostream>

using namespace std;

int n, D = 1, ans;

int main()
{
	while(cin >> n){
		while(1){
			D %= n;
			ans++;
			
			if(D == 0)	break;
			else		D = 10 * D + 1;
		}
		cout << ans << "\n";
		
		D = 1; ans = 0;
	}
	
    return 0;
}