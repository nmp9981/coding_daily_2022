#include <iostream>
using namespace std;

int n;
const int maxi = 1000001;
int dp[maxi];

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//연속 LIS구하기
void continueLIS() {
	int maxLen = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dp[x] = dp[x - 1] + 1;
		maxLen = max(maxLen, dp[x]);
	}
	cout << n - maxLen;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	continueLIS();//연속 LIS 구하기
	return 0;
}
