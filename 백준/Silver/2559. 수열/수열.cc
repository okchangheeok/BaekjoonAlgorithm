#include <bits/stdc++.h>
using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    int arr[N];
    int sum[N - K + 1];
    //memset(sum, 0, sizeof(sum));
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    //for(int i = 0; i < N - K + 1; i++)
    //    sum[i] = accumulate(arr + i, arr + K + i, 0);
    
    sum[0] = accumulate(arr, arr + K, 0);
    for(int i = 1; i < N - K + 1; i++){
        sum[i] = sum[i - 1] - arr[i - 1] + arr[i + K - 1];
    }
    // for(int i = 0; i < N - K + 1; i++)
    //     cout << sum[i] << " ";
    cout << *max_element(sum, sum + N - K + 1);
    
    return 0;
}