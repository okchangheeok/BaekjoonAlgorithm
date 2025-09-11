#include <iostream>
#include <string>

using namespace std;

string name;
int age, weight;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	while(1){
		cin >> name >> age >> weight;
		if(name == "#") break;
		
		cout << name << " ";
		if(17 < age || 80 <= weight)	cout << "Senior\n";
		else							cout << "Junior\n";
	}

    return 0;
}