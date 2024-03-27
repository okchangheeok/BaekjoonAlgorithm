#include <bits/stdc++.h>
using namespace std;

int N;
string str;
map<char, int> mp;
bool flag;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        mp[str[0]]++;
    }
    
    for(auto i : mp)
        if(i.second >= 5){
            cout << i.first;
            flag = 1;
        }
    
    if(flag != 1)
        cout << "PREDAJA";
    
    return 0;
}
