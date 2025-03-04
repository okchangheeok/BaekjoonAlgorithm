#include <bits/stdc++.h>

using namespace std;

int N, tmp, pls[4] = {1, 3, 7, 9};
vector<vector<int>> v(9);

bool ck_sosoo(int a){
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0)
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    v[1].push_back(2);
    v[1].push_back(3);
    v[1].push_back(5);
    v[1].push_back(7);
	for(int i = 2; i <= N; i++)
		for(int it: v[i - 1])
			for(int j = 0; j < 4; j++){
				tmp = 10 * it + pls[j];
				if(ck_sosoo(tmp))
					v[i].push_back(tmp);
			}
	
	for(auto it: v[N])
		cout << it << "\n";
	
    return 0;
}