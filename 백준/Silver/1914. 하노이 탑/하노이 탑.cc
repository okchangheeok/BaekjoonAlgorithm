#include <iostream>
#include <string.h>
using namespace std;

string bignum_cal(string str){
  // X2
  for(int i = str.length() - 1; i >= 0; i--){
    if((str[i] - '0') >= 5){
      if(i == str.length() - 1)
        str += "1";
      else
        str[i + 1]++;
    }
    str[i] = '0' + ((str[i] - '0') * 2) % 10;  
    }
  // +1
  str[0] += 1;
  return str;
}



void print_count(int N, string str = "1"){
  if(N <= 1){
    for(int i = (str.length() - 1); i >= 0; i--)
      cout << str[i];
    cout << "\n";
    return;
  }
  print_count(N - 1, bignum_cal(str));
}

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