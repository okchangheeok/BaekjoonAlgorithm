#include <iostream>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int R, C, ans;
char cd[1005][1005];
int visited[1005][1005];
queue<pair<int, int>> qJ;
queue<pair<int, int>> qF;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

void spread_F(){
	int yF, xF;
	int qF_len = qF.size();
	for(int i = 0; i < qF_len; i++){
		tie(yF, xF) = qF.front(); qF.pop();
		
		for(int j = 0; j < 4; j++){
			int nyF = yF + dy[j];
			int nxF = xF + dx[j];
			
			if(nyF < 0 || R <= nyF || nxF < 0 || C <= nxF) continue;
			if(cd[nyF][nxF] == '.' || cd[nyF][nxF] == 'J'){
				cd[nyF][nxF] = 'F';
				qF.push({nyF, nxF});
			}
		}
	}
}

void spread_J(){
	int yJ, xJ;
	int qJ_len = qJ.size();
	
	for(int i = 0; i < qJ_len; i++){
		tie(yJ, xJ) = qJ.front(); qJ.pop();
		
		if(cd[yJ][xJ] == 'F') continue;
		
		if((0 == yJ || yJ == R - 1) || (0 == xJ || xJ == C - 1)){
			ans = visited[yJ][xJ] + 1;
			return;
		}
		
		for(int i = 0; i < 4; i++){
			int nyJ = yJ + dy[i];
			int nxJ = xJ + dx[i];
			
			if(cd[nyJ][nxJ] == '.'){
				cd[nyJ][nxJ] = 'J';
				qJ.push({nyJ, nxJ});
				visited[nyJ][nxJ] = visited[yJ][xJ] + 1;
			}
		}
	}
}

int main(){ 
    cin >> R >> C;
    
    for(int i = 0; i < R; i++){
    	for(int j = 0; j < C; j++){
    		cin >> cd[i][j];
    		
    		if(cd[i][j] == 'F')			qF.push({i, j});
    		else if(cd[i][j] == 'J')	qJ.push({i, j});
		}
	}
	
	while(1){
		spread_J();
		if(qJ.empty() || ans) break;
		spread_F();
	}
	
	if(ans)	cout << ans;
	else	cout << "IMPOSSIBLE";	
	
	return 0;
}