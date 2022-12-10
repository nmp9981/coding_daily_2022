#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
const int maxi = 1001;
vector<int> man; vector<int> woman;//남녀 성격
int diff[maxi][maxi];//성격차
int diffSum[maxi][maxi];//성격차의 합

//절댓값
inline int abs(int x) {
	return x > 0 ? x : -x;
}
//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		man.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int b; cin >> b;
		woman.push_back(b);
	}
	sort(man.begin(), man.end());//오름차순 정렬
	sort(woman.begin(), woman.end());
}
//성격차
void CharacterDiff() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) diff[i][j] = abs(man[i-1] - woman[j-1]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) diffSum[i][j] = diffSum[i - 1][j - 1] + diff[i][j];//매칭
			else if (i > j) diffSum[i][j] = min(diffSum[i - 1][j], diffSum[i - 1][j - 1] + diff[i][j]);//남자가 솔로
			else if (i < j) diffSum[i][j] = min(diffSum[i][j-1], diffSum[i - 1][j - 1] + diff[i][j]);//여자가 솔로
		}
	}
}
//결과
int Result() {
	int ans = diffSum[n][m];//모두 매칭
	if (n > m) {//여자 매칭 완료
		for (int i = m+1; i <= n; i++) ans = min(ans, diffSum[i][m]);
	}
	else if (n < m) {//남자 매칭 완료
		for (int j = n+1; j <= m; j++) ans = min(ans, diffSum[n][j]);
	}
	return ans;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
  input();//입력
	CharacterDiff();//성격차
	cout<<Result();//결과
	return 0;
}
