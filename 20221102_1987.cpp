#include <iostream>
#pragma warning(disable:4996)//scanf에러 무시
using namespace std;

int R,C,ans;
const int maxi = 21;
const int alphaMaxi = 26;
string board[maxi];//보드판
bool alpha[alphaMaxi];//해당 알파벳 방문여부
//4방 탐색
int dr[4] = { 0,0,-1,1 };
int dc[4] = { -1,1,0,0 };

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> R>>C;
	for (int i = 0; i < R; i++) cin >> board[i];
	alpha[board[0][0] - 'A'] = true;//시작지점 방문체크
}
//이동(위치, 방문 개수)
void move(int r, int c, int cnt) {
	ans = max(ans, cnt);//갱신
	//다음 지점
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;//범위조건
		if (alpha[board[nr][nc] - 'A'] == true) continue;//방문조건

		alpha[board[nr][nc] - 'A'] = true;
		move(nr, nc, cnt + 1);//다음 지점
		alpha[board[nr][nc] - 'A'] = false;
	}
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	move(0, 0, 1);//이동(위치, 방문 개수)
	cout << ans;//출력
	return 0;
}
