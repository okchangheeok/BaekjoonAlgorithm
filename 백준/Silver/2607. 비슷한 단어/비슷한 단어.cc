#include <iostream>

int main() {
	int N;
	std::cin >> N;
	int STD[N][26];
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < 26; j++)
			STD[i][j] = 0;
	
	std::string arr[N];
	for(int i = 0; i < N; i++)		//N개의 문자열 배열에 저장.
		std::cin >> arr[i];
	for(int i = 0; i < N; i++)
		for(int j = 0; arr[i][j]; j++)
			STD[i][arr[i][j] - 'A']++;

	int zerosum;
	int numsum;
	int flag;
	int diff;
	zerosum = 0;
	numsum = 0;
	for(int i = 0; i < 26; i++)
		zerosum += STD[0][i];
	flag = 0;
	for(int i = 1; i < N; i++){
		diff = 0;
		for(int j = 0; j < 26; j++){	//모든 범위에서의 차이가 0, 1인지 확인.
			diff += abs(STD[i][j] - STD[0][j]);
			if(diff == 3)				//다시보기
				break;
		}
		if(diff == 0 || diff == 1)
			flag++;
		else if(diff == 2){
			for(int j = 0; j < 26; j++)
				numsum += STD[i][j];
			if(numsum == zerosum)
				flag++;
			numsum = 0;
		}										//else if( == 2) 총 배열의 합이 같으면 flag++
	}

	std::cout << flag;
	// std::cin >> X;
	// int arr[N];
	// for (int i = 0; i < N; i++)
	// 	std::cin >> arr[i];
	// for (int i = 0; i < N; i++)
	// 	if (arr[i] < X)
	// 		std::cout << arr[i] << " ";
	return 0;
}