#include <bits/stdc++.h>

using namespace std;

long N, C, tmp;
map<long, long> mp;
vector<pair<long, long>> v;
vector<int> num;

bool compare(pair<long, long>& a, pair<long, long>& b)
{
    if(a.first != b.first)
	    return a.first > b.first;
	else
	    return find(num.begin(), num.end(), a.second) < find(num.begin(), num.end(), b.second);
}

int main()
{
    cin >> N >> C;
    
    for(int i = 0; i < N; i++){
        cin >> tmp;
        mp[tmp]++;
        if(find(num.begin(), num.end(), tmp) == num.end())
            num.push_back(tmp);
    }
    for(long it: num){
        v.push_back({mp[it], it});
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].first; j++)
            cout << v[i].second << " ";
    return 0;
}