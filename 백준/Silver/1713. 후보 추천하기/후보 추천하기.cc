#include <bits/stdc++.h>

using namespace std;

int N, M, tmp, last, MIN = 105;
vector<int> pic;
map<int, int> rec;

int main()
{
	cin >> N >> M;
	while(M--){
		cin >> tmp;
		//벡터에 현재 값이 없을 때
		if(find(pic.begin(), pic.end(), tmp) == pic.end()){
			//후보들이 꽉찼을 때 
			if(N <= pic.size()){
				//처음으로 발견한 최소 추천횟수 후보 제거 
				for(int it: pic)
					if(rec[it] < MIN){
						MIN = rec[it];
						last = it;
					}
				pic.erase(find(pic.begin(), pic.end(), last));
				rec.erase(rec.find(last));
				MIN = 105;	
			}
			pic.push_back(tmp);
		}
		rec[tmp]++;
	}
	
	sort(pic.begin(), pic.end());
	
	for(auto it: pic)
		cout << it << " ";
	
    return 0;
}