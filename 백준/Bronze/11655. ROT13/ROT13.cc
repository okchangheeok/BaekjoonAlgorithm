#include <bits/stdc++.h>
using namespace std;

string str;

int main()
{
    getline(cin, str);
    
    for(int i = 0; i < str.size(); i++){
        if(('a' <= str[i] && str[i] <= 'm') || ('A' <= str[i] && str[i] <= 'M'))
            str[i] += 13;
        else if(('n' <= str[i] && str[i] <= 'z') || ('N' <= str[i] && str[i] <= 'Z'))
            str[i] -= 13;
    }
    cout << str;
    return 0;
}
