#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
const int maxi = 1000001;
int A[maxi];//수열
vector<int> lis;//LIS 벡터

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
}

//LIS
void LIS() {
	for (int i = 0; i < n; i++) {
		//가장 큰 수
		if (lis.size() == 0 || A[i] > lis[lis.size() - 1]) {
			lis.push_back(A[i]);
		}
		else {
			int pos = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();//위치
			lis[pos] = A[i];//갱신
		}
	}
	cout<< lis.size();//길이 출력
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	LIS();//LIS
    return 0;
}
