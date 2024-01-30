#include <iostream>

int main() {
	int N;
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
	
	diff = 0;
	flag = -1; 						//이후에 더해질 자기자신 제외.

	for(int i = 0; i < N; i++){
		for(int j = 0; num[i][j]; j++)
			count_alp[i][num[i][j] - 'A']++;
		for(int j = 0; j < 26; j++)
			diff += abs(count_alp[i][j] - count_alp[0][j]);
		
		if(diff == 0 || diff == 1)	//모든 범위에서의 차이가 0, 1인지 확인.
			flag++;
		else if(diff == 2 && num[i].length() == num[0].length())
			flag++;						//else if( == 2) 글자수가 같으면 flag++
		diff = 0;
	}
	std::cout << flag;
	return 0;
}