#include <bits/stdc++.h>
using namespace std;

int N, M;

map<string, int> mp;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    string pokarr[N];
    string quest[M];
    for(int i = 0; i < N; i++){
        cin >> pokarr[i];
        mp[pokarr[i]] = i;
    }
    for(int i = 0; i < M; i++)
        cin >> quest[i];
    for(int i = 0; i < M; i++){
        if(quest[i][0] >= '1' && quest[i][0] <= '9')
            cout << pokarr[stoi(quest[i]) - 1] << "\n";
        else
            cout << mp[quest[i]] + 1 << "\n";
            // for(int j = 0; j < N; j++)
            //     if(pokarr[j] == quest[i]){
            //         cout << j + 1 << "\n";
            //         break;
            //     }
    }
}

// map<int, string> mp;

// int main()
// {
//     cin >> N >> M;
//     string quest[M];
//     for(int i = 0; i < N; i++)
//         cin >> mp[i + 1];
//     for(int i = 0; i < M; i++)
//         cin >> quest[i];
//     for(int i = 0; i < M; i++){
//         if(quest[i][0] >= '1' && quest[i][0] <= '9')
//             cout << mp[stoi(quest[i])];
//         else{
//             auto it = mp.find(quest[i]);
//             cout << (*it).first;
//         }
//     }
// }