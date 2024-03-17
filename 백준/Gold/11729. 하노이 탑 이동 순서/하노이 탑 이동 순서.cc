#include <iostream>
#include <cmath>
using namespace std;

void print_count(int N, int answer = 1){
  if(N <= 1){
    cout << answer << "\n";
    return;
  }
  print_count(N - 1, 2 * answer + 1);
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
  print_process(N);
  return 0;
}