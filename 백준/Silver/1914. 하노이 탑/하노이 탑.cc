#include <iostream>
#include <string.h>
using namespace std;

void print_count2(int N){
  string str = "2";
  for(int i = 1; i < N; i++)
    for(int j = str.length() - 1; j >= 0; j--){   //1의자리에서 먼 자릿수부터 시작
      if((str[j] - '0') >= 5){                    //(j+1)부터 고려 - 5보다 크다면 하나 큰 자릿수에 1을 더해야 함.
        if(j == str.length() - 1)                 //첫번째 루프라면 1을 append
          str += "1";
        else                                      //이미 값이 존재할땐 +1
          str[j + 1]++;
      }
      str[j] = '0' + ((str[j] - '0') * 2) % 10;   //(j)고려 - 5보다 크든작든 2를 곱한 뒤 10으로 나눈 값으로 업데이트
    }
  str[0] -= 1;                                    //1의자리에 -1을 함(위는 2의 거듭제곱이기에 0이 나올 리 없으니 예외처리 필요없음)

  for(int i = (str.length() - 1); i >= 0; i--)
    cout << str[i];
  cout << "\n";
}

// string으로 표현된 수를 2와 곱하고 1을 더하는 함수
string bignum_cal(string str){                    //1의 자리가 index가 0인 부분부터 시작
  // X2
  for(int i = str.length() - 1; i >= 0; i--){     //1의자리에서 먼 자릿수부터 시작
    if((str[i] - '0') >= 5){                      //(i+1)부터 고려 - 5보다 크다면 하나 큰 자릿수에 1을 더해야 함.
      if(i == str.length() - 1)                   //첫번째 루프라면 1을 append
        str += "1";
      else                                        //이미 값이 존재할땐 +1
        str[i + 1]++;
    }
    str[i] = '0' + ((str[i] - '0') * 2) % 10;     //(i)고려 - 5보다 크든작든 2를 곱한 뒤 10으로 나눈 값으로 업데이트
  }
  // +1
  str[0] += 1;                                    //1의자리에 +1을 함(위에서 2배를 진행했기에 9가 나올 리 없으니 예외처리 필요없음)
  return str;
}
 //
// 옮기는 횟수를 세는 함수
void print_count(int N, string str = "1"){
  if(N <= 1){
    for(int i = (str.length() - 1); i >= 0; i--)
      cout << str[i];
    cout << "\n";
    return;
  }
  print_count(N - 1, bignum_cal(str));
}

// 옮기는 경로를 출력하는 함수
void print_process(int N, int A = 1, int B = 2, int C = 3){
  if(N <= 1){
    cout << A << " " << C << "\n";
    return;
  }

  print_process(N - 1, A, C, B);
  cout << A << " " << C << "\n";
  print_process(N - 1, B, A, C);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N;
  cin >> N;

  print_count(N);
  if(N <= 20)
    print_process(N);
  return 0;
}