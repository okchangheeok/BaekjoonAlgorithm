#include <bits/stdc++.h>
using namespace std;

int N;
string A1;
string tmp;
vector<string> vec_std;
vector<string> vec;
queue<string> ret;

vector<string> split(string str){
    vector<string> ret;
    ret.push_back(str.substr(0, str.find("*")));
    ret.push_back(str.substr(str.find("*") + 1, str.size() - str.find("*") + 1));
    
    return ret;
}

int main()
{
    cin >> N;
    cin >> A1;
    vec_std = split(A1);
    for(int i = 0; i < N; i++){
        cin >> tmp;
        vec.push_back(tmp);
        if(vec[i].size() < A1.size() - 1)
            ret.push("NE");
        else if((vec[i].substr(0, vec_std[0].size()) == vec_std[0]) && (vec[i].substr(vec[i].size() - vec_std[1].size()) == vec_std[1]))
            ret.push("DA");
        else
            ret.push("NE");
    }
    
    while(ret.size()){
        cout << ret.front() << '\n';
        ret.pop();
    }
    return 0;
}