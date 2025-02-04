#include <bits/stdc++.h>

using namespace std;

int N, first, flag;
string str[70];
string ans;
int cd[70][70];

int dy(int n, int idx){
	return (idx / 2) * (n / 2);
}

int dx(int n, int idx){
	return (idx % 2) * (n / 2);
}
void dfs(int y, int x, int n){
	if(n != 1) ans += "(";
	for(int idx = 0; idx < 4; idx++){
		flag = 1;
		first = cd[y + dy(n, idx)][x + dx(n, idx)];
		for(int i = y + dy(n, idx); i < y + dy(n, idx) + n / 2; i++){
			for(int j = x + dx(n, idx); j < x + dx(n, idx) + n / 2; j++){
				if(cd[i][j] != first){
					dfs(y + dy(n, idx), x + dx(n, idx), n / 2);
					flag = 0;
					break;
				}
			}
			if(flag == 0)
				break;
		}
		if(flag == 1)
			ans += '0' + first;
	}
	if(n != 1) ans += ")";
}

int main(){
	cin >> N;
	if(N == 1){
		cin >> N;
		cout << N;
		exit (0);
	}
	for(int i = 0; i < N; i++){
		cin >> str[i];
		for(int j = 0; j < N; j++)
			cd[i][j] = str[i][j] - '0';	
	}
	dfs(0, 0, N);
	
	if(ans.size() == 6)
		if(ans[1] == ans[2])
			if(ans[1] == ans[3])
				if(ans[1] == ans[4]){
					cout << ans[1];
					exit (0);
				}
	cout << ans;
	
	
	return 0;
}