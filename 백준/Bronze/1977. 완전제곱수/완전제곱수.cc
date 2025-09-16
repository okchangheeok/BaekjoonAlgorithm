#include <iostream>
#include <cmath>

using namespace std;

int M, N, n, ans1, ans2;
bool flag;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> M >> N;
    n = sqrt(N);
    if(pow(n, 2) < M) flag = true;
    while(1){
    	ans2 = pow(n, 2);
    	ans1 += ans2;
		n--;
    	if(pow(n, 2) < M){
    		break;
		}
	}
	
	if(flag)	cout << -1;
	else		cout << ans1 << "\n" << ans2;
	
    return 0;
}