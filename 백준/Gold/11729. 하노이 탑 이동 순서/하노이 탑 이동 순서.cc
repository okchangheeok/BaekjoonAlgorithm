#include <iostream>
using namespace std;

//이동 횟수 계산 후 출력 함수
//N부터 역방향으로 1까지 가면서 매 회 (전 단계 횟수) * 2 + 1 진행.
void print_count(int N, int answer = 1){
  if(N <= 1){
    cout << answer << "\n";
    return;
  }
  print_count(N - 1, 2 * answer + 1);
}

//이동 경로 출력 함수
//N부터 역방향으로 1까지 가면서 매 회 전 단계 과정 출력, A/C 출력, 전 단계 과정 출력 진행.
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