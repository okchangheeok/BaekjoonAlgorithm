#include <iostream>

int main() {
	int N;
	int letnum_first;
	int letnum_rm;
	int diff;
	int flag;
	
	std::cin >> N;
	int count_alp[N][26];
	for(int i = 0; i < N; i++)
		for(int j = 0; j < 26; j++)
			count_alp[i][j] = 0;
	
	std::string num[N];
	for(int i = 0; i < N; i++)		//N개의 문자열 배열에 저장.
		std::cin >> num[i];

	for(int i = 0; i < N; i++)
		for(int j = 0; num[i][j]; j++)
			count_alp[i][num[i][j] - 'A']++;

	letnum_first = 0;
	
	for(int i = 0; i < 26; i++)
		letnum_first += count_alp[0][i]; //첫 단어 갯수 세기
	
	letnum_rm = 0;
	diff = 0;
	flag = 0; 						//이후에 더해질 자기자신 제외.

	for(int i = 1; i < N; i++){
		for(int j = 0; j < 26; j++)
			diff += abs(count_alp[i][j] - count_alp[0][j]);
		if(diff == 0 || diff == 1)	//모든 범위에서의 차이가 0, 1인지 확인.
			flag++;
		else if(diff == 2){
			for(int j = 0; j < 26; j++)
				letnum_rm += count_alp[i][j];
			if(letnum_rm == letnum_first)
				flag++;
			letnum_rm = 0;
		}										//else if( == 2) 총 배열의 합이 같으면 flag++
		diff = 0;
	}
	// flag -= 1;
	std::cout << flag;
	return 0;
}