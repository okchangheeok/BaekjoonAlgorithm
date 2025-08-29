#include <iostream>
#include <string>

using namespace std;

int N;
string stdd, pre, suf, tmp;

string chk(string a){
	string ret = "0";
	if(a.size() < stdd.size() - 1) ret = "NE\n";
	else if(a.substr(0, pre.size()) == pre && a.substr(a.size() - suf.size()) == suf)
		ret = "DA\n";
	else ret = "NE\n";
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> stdd;
	
	auto l = stdd.find('*');
	pre = stdd.substr(0, l);
	suf = stdd.substr(l + 1);
	
	for(int i = 0; i < N; i++){
		cin >> tmp;
		cout << chk(tmp);
	}
	
    return 0;
}