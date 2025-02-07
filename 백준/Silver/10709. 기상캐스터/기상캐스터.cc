#include <bits/stdc++.h>

using namespace std;

int H, W, flag, ans;
char c;

int main()
{
    cin >> H >> W;
    for(int i = 0; i < H; i++){
    	for(int j = 0; j < W; j++){
    		cin >> c;
    		if(c == '.' && flag == 0)
    			ans = -1;
    		else if(c == 'c'){
    			ans = 0;
    			flag = 1;
			}
    		else if(c == '.' && flag == 1)
    			ans += 1;
    		cout << ans << " ";
    	}
    	cout << "\n";
    	flag = 0;
		ans = 0;	
    }
    
    
    return 0;
}