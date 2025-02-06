#include <bits/stdc++.h>

using namespace std;

int N, M, tmp;
vector<int> v;

void print(vector<int> v2){
    for(int i: v2) cout << i << " ";
    cout << "\n";
}

void combi(int start, vector<int> v1){
    if(v1.size() == M){
        print(v1);
        return;
    }
    for(int i = start; i < v.size(); i++){
        if(v1.size() > 0 && (v1[v1.size() - 1] > v[i])) continue;
        v1.push_back(v[i]);
        combi(start, v1);
        v1.pop_back();
    }
    return;
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    vector<int> tmp_v;
    combi(0, tmp_v);
    
    return 0;
}