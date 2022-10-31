#include <iostream>
using namespace std;
#pragma warning(disable:4996) // C4996 에러를 무시

int n, m,ans;
const int maxi = 1003;
int board[maxi][maxi];//보드판
int dp[maxi][maxi];//최대 한변의 길이

//min
inline int min(int x, int y) {
	return x < y ? x : y;
}
//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) scanf("%1d", &board[i][j]);
	}
}
//넓이
void square() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1) {
				dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
				ans = max(ans, dp[i][j]);
			}
		}
	}
	std::cout << ans * ans;
}
int main() {
	//빠른 입력
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	input();//입력
	square();//넓이
	return 0;
}
