#include <bits/stdc++.h>
using namespace std;
int price[3];
int ttmm[2];
map<int, int> mp;
int ret;

int main()
{
    for(int i = 0; i < 3; i++){
        cin >> price[i];
        price[i] *= (i + 1);
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++)
            cin >> ttmm[j];
        for(int j = ttmm[0]; j < ttmm[1]; j++)
            mp[j]++;
    }
    
    for(auto i: mp)
        ret += price[i.second - 1];
        
    cout << ret;
    
    return 0;
}