#include <bits/stdc++.h>
using namespace std;

int N, M, ret, key, idx;
int numarr[15005];

int main()
{
    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
        cin >> numarr[i];
    sort(numarr, numarr + N);
    
    for(idx = N - 1; idx >= 0; idx--)
        if(numarr[idx] < M)
            break;
    if(numarr[idx] + numarr[idx - 1] > M)
        for(int i = idx; i > key; i--){
            while(numarr[key] + numarr[i]< M)
                key++;
            if(numarr[key] + numarr[i] == M){
                ret++;
                key++;
            }
        }
    
    cout << ret;
    
    return 0;
}