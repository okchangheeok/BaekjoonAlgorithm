#include <iostream>
using namespace std;

int main() {
  int A;
  int B;
  int V;
  int day;
  int height;
  
  cin >> A;
  cin >> B;
  cin >> V;

  day = (V - A) / (A - B);
  height = (A - B) * day;

  while(1){
    day++;
    height += A;
    if (height >= V)
      break;
    height -= B;
  }

  cout << day;
  return 0;
}