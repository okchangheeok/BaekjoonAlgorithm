#include <iostream>
using namespace std;

int main() {
  int N;
  int K;
  int answer;

  cin >> N;
  cin >> K;
  answer = 0;

  int coin[N];
  for(int i = 0; i < N; i++)
    cin >> coin[i];
  
  for(int i = N - 1; i >= 0; i--)
    if (coin[i] <= K){
      answer += K / coin[i];
      K %= coin[i];
      if (K == 0)
        break;
    }
  
  cout << answer;
  return 0;
}