#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  int A[N];
  int B;
  int C;
  long int answer;

  for (int i = 0; i < N; i++)
    cin >> A[i];
  cin >> B;
  cin >> C;

  answer = (long int)N; //시험장 수 = 총감독관 수 미리 고려
  for (int i = 0; i < N; i++) {
    if (A[i] > B) {             //총 감독관으로 감당 불가 시
      answer += (long int)((A[i] - B) / C); //부감독관으로 나눈 몫을 answer에 더함
      if ((A[i] - B) % C)       //나머지 있을 시 한명 더 더함
        answer++;
    }
  }

  cout << answer;

  return 0;
}