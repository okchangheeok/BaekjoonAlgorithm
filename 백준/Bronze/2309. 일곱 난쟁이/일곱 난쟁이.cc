#include <bits/stdc++.h>
using namespace std;

int arr[13], sum, i, j, flag;

int main()
{
    //입력받자
    for(int i = 0; i < 9; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + 9);
    //100맞추자
    sum -= 100;
    for(i = 0; i < 9; i++){ //조합으로 2개씩 뽑아서 100외에 두 녀석인지 확인.
        for(j = i + 1; j < 9; j++)
            if(arr[i] + arr[j] == sum){
                flag = 1;
                break;
            }
        if(flag == 1)
            break;
    }
    for(int z = 0; z < i; z++)// 그 두녀석 빼고 나머지 출력.
        cout << arr[z] << '\n';
    for(int z = i + 1; z < j; z++)
        cout << arr[z] << '\n';
    for(int z = j + 1; z < 9; z++)
        cout << arr[z] << '\n';
    
    return 0;
}