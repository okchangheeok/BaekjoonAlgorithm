#include <bits/stdc++.h>

using namespace std;

int N, K;
int w, v, ans[100005];

int main()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++){
    	cin >> w >> v;
    	for(int j = K; w <= j; j--)
    		ans[j] = max(ans[j], ans[j - w] + v);
    }
	
	cout << ans[K];
}