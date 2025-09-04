#include <iostream>
#include <string>

using namespace std;

int N;
string tmp, ans;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	
	cin >> N;
	while(N--){
		cin >> tmp;
		if(ans == "") ans = tmp;
		else
			for(int i = 0; i < ans.size(); i++)
				if(ans[i] != tmp[i]) ans[i] = '?';
	}
	
	cout << ans;
	
    return 0;
}