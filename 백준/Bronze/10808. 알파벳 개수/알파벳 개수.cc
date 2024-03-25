#include <bits/stdc++.h>
using namespace std;

string str;
map<char, int> mp;

int main()
{
    cin >> str;
    
    for(auto i : str)
        mp[i]++;
    
    for(char i = 'a'; i <= 'z'; i++)
        cout << mp[i] << " ";
    return 0;
}