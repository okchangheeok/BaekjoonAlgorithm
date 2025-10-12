#include <iostream>
#include <string>
using namespace std;

string A, B;
char op;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> op >> B;
	if(op == '*'){
		cout << A;
		for(int i = 0; i < B.size() - 1; i++)
			cout << '0';
	}
	else{
		if(A.size() > B.size()){
			A[A.size() - B.size()] = '1';
			cout << A;
		}
		else if(A.size() < B.size()){
			B[B.size() - A.size()] = '1';
			cout << B;
		}
		else{
			A[0] = '2';
			cout << A;
		}
	}

	return 0;
}