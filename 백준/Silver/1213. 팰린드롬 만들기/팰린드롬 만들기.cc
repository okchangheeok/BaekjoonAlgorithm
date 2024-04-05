#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;
string ipt, half;
char odd;
int flag;
int main()
{
    cin >> ipt;
    for(int i = 0; i < ipt.size(); i++)
        mp[ipt[i]]++;
    for(auto it : mp)
        if(it.second % 2 == 1){
            if(flag == 1){
                cout << "I'm Sorry Hansoo";
                flag++;
                break;
            }
            flag++;
            odd = it.first;
            it.second--;
        }
    if(0 <= flag && flag <= 1){
        for(auto it : mp){
            for(int i = 0; i < it.second/2; i++)
                half += it.first;
        }
        cout << half;
        if(flag)
            cout << odd;
        
        reverse(half.begin(), half.end());
        cout << half;
    }
    return 0;
}
