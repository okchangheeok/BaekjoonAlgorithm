#include <iostream>
#include <string>

using namespace std;

string inp;
int loc[4] = {1, 0, 0, 2};

void ch(char c){
	int tmp;
	if(c == 'A'){
		tmp = loc[0];
		loc[0] = loc[1];
		loc[1] = tmp;
	}
	if(c == 'B'){
		tmp = loc[0];
		loc[0] = loc[2];
		loc[2] = tmp;
	}
	if(c == 'C'){
		tmp = loc[0];
		loc[0] = loc[3];
		loc[3] = tmp;
	}
	if(c == 'D'){
		tmp = loc[1];
		loc[1] = loc[2];
		loc[2] = tmp;
	}
	if(c == 'E'){
		tmp = loc[1];
		loc[1] = loc[3];
		loc[3] = tmp;
	}
	if(c == 'F'){
		tmp = loc[2];
		loc[2] = loc[3];
		loc[3] = tmp;
	}
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> inp;
	for(char it: inp)
		ch(it);
	
	for(int i = 0; i < 4; i++)
		if(loc[i] == 1) cout << i + 1 << "\n";
	for(int i = 0; i < 4; i++)
		if(loc[i] == 2) cout << i + 1 << "\n";
	
    return 0;
}