#include <iostream>

using namespace std;

int N, K, tmp, ans = -10000005;
int psum[100005];

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }
    
    for(int i = K; i <= N; i++)
        ans = max(ans, psum[i] - psum[i - K]);
    
    cout << ans;
    
    return 0;
}