#include <iostream>

using namespace std;

int A, B, C;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> A >> B >> C;
	A += C / 60;
	B += C % 60;
	
	if(59 < B){
		A += 1;
		B -= 60;
	}
	if(23 < A) A -= 24;
	
	cout << A << " " << B;
	
    return 0;
}