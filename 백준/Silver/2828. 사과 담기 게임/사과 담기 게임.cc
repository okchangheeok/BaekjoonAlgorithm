#include <bits/stdc++.h>

using namespace std;

int N, M, J, cd, ap, ans;

int main()
{
    cd = 1;
    cin >> N >> M >> J;
    for(int i = 0; i < J; i++){
        cin >> ap;
        if(cd <= ap && ap <= cd + M - 1)
            continue;
        else if(ap < cd){
            ans += cd - ap;
            cd = ap;
        }
        else{
            ans += ap - (cd + M - 1);
            cd = ap - (M - 1);
        }
    }
    
    cout << ans;
    
    return 0;
}