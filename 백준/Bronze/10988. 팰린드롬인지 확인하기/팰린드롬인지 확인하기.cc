#include <bits/stdc++.h>
using namespace std;

string str, rev;

int main()
{
    cin >> str;
    rev = str;
    reverse(rev.begin(), rev.end());
    if(rev == str)
        cout << "1";
    else
        cout << "0";
    
    return 0;
}