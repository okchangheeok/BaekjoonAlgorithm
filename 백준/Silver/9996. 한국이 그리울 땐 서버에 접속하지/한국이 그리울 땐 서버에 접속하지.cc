#include <iostream>
#include <string>

using namespace std;

int N;
string pat, pre, suf, tmp;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	//1
	cin >> N;
	//2
	cin >> pat;
	
	int i = pat.find('*');
	pre = pat.substr(0, i);
	suf = pat.substr(i + 1);
	//3~
	while(N--){
		cin >> tmp;
		
		if(tmp.size() < pat.size() - 1)
			cout << "NE\n";
		else if(tmp.substr(0, pre.size()) == pre && tmp.substr(tmp.size() - suf.size()) == suf)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	
	return 0;
}