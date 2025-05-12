#include <bits/stdc++.h>

using namespace std;

int n, k, cv;
int arr[10005];
const int INF = 987654321;

int main()
{
    fill(arr, arr + 10005, INF);
    arr[0] = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> cv;
        for(int j = cv; j <= k; j++)
            arr[j] = min(arr[j], arr[j - cv] + 1);
    }
    if(arr[k] == INF)
        cout << -1;
    else
        cout << arr[k];
    return 0;
}