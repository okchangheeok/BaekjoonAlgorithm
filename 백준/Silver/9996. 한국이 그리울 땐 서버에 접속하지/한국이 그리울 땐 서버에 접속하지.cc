#include <iostream>
#include <string>

using namespace std;

int N;
string stdd, pre, nex, tmp;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin >> N;
	cin >> stdd;
	
	int i = stdd.find('*');
	pre = stdd.substr(0, i);
	nex = stdd.substr(i + 1);
	
	while(N--){
		cin >> tmp;
		if(tmp.size() < stdd.size() - 1) cout << "NE\n";
		else if(tmp.substr(0, pre.size()) == pre && tmp.substr(tmp.size() - nex.size()) == nex)
			cout << "DA\n";
		else cout << "NE\n";
	}
	
	return 0;
}