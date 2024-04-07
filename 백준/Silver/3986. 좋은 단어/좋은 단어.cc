#include <bits/stdc++.h>
using namespace std;

int N, str_size, idx, ret;
string str;
map<int, int, greater<int>> mp;

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        str_size = str.size();
        for(int j = 0; j < str_size - 1; j++){
            // cout << "j: " << j << "\n";
            idx = j;
            if(str[j + 1] == str[j]){
                while(str[idx] == str[j])
                    idx++;
                str.erase(j, (idx - j) / 2 * 2);
                str_size = str.size();
                // cout << "str: " << str << "\n";
                j = (j == 0)? j-1 : j-2;
            }
        }
        
        if(!str.size())
            ret++;

        str.clear();
    }
    cout << ret;
    return 0;
}


//         while(1){
//             //삭제될 때 여기서 문제 일으킴.!!!!!!!!!!!!!!!!!!!!
//             while(idx < str.size() - 1){
//                 if(str[idx] == str[idx + 1]){
//                     // cout << "YES" << "\n";
//                     for(int j = idx; str[j] == str[idx]; j++)
//                         mp[idx]++;
//                     mp[idx] /= 2;
//                     mp[idx] *= 2;
//                     // cout << "(before) " << idx << " : " << mp[idx] << "\n";
//                     idx += mp[idx];//1번 string 호출 안할 수 있음.
//                     // cout << "(after) " << idx << "\n";
//                 }
//                 else
//                     idx++;
//             }
//             idx = 0;
//             // for(auto it : mp)
//                 // cout << "mp " << it.first << " : " << it.second << "\n";
//             for(auto it : mp)
//                 str.erase(it.first, it.second);
//             //if 다없어졌음 break;
//             if(!str.size()){
//                 mp.clear();
//                 ret++;
//                 // cout << i << ": !str.size()" << "\n";
//                 break;
//             }
//             //if 바뀐거 없음 break;
//             if(!mp.size()){
//                 mp.clear();
//                 // cout << i << ": !mp.size()" << "\n";
//                 break;
//             }
//             mp.clear();
//         }






// }
// if(!str.size())//for문 응급처치;
//     ret++;


// }
//     if(!str.size())//for문 응급처치;
//         break;
//     }
    
//     if(!str.size()){
//         ret++;
//         break;
//     }
// }
//     cout << ret;
    
//     return 0;
// }

// int main()
// {
//     //짝수인지 체크 추가.
//     cin >> N;
//     for(int i = 0; i < N; i++){
//         cin >> str;
//         flag = 1;
//         while(flag){
//             flag = 0;
//             //삭제될 때 여기서 문제 일으킴.!!!!!!!!!!!!!!!!!!!!
//             for(int j = 0; j < str.size() - 1; j++){
//                 while(str.size() && str[j] == str[j + 1]){
//                     str.erase(j, 2);
//                     flag++;
//                 }
//                 if(!str.size())
//                     break;
//             }
//             //for is not okay;
//             if(!str.size()){
//                 ret++;
//                 break;
//             }
//         }
//         str.clear();
//     }
//     cout << ret;
    
//     return 0;
// }