#include <bits/stdc++.h>
using namespace std;

int T, N, ans;
map<string, int> mp;
string tmp;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int i = 0; i < T; i++){
        ans = 1;
        
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> tmp >> tmp;
            mp[tmp]++;
        }
        for(auto it : mp){
            ans *= it.second + 1;
        }
        
        cout << ans - 1 << '\n';
        mp.clear();
    }
    
    return 0;
}
