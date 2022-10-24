#include <iostream>
#pragma warning(disable:4996)//scanf에러 무시
using namespace std;

const int alphaMaxi = 26;
const int maxi = 21;
bool alphabet[alphaMaxi];//알파벳 선택 여부
string board[maxi];//지도
bool visit[maxi][maxi];//방문 여부
int R, C,maxCnt;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

//max
int inline max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> board[i];
	alphabet[board[0][0] - 'A'] = true;//방문 체크
}
//말 이동
void Move(int r,int c,int cnt) {
	maxCnt = max(cnt, maxCnt);
	//다음 지점
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;//범위 조건
		if (alphabet[board[nr][nc] - 'A']==true) continue;//이미 방문한 알파벳

		alphabet[board[nr][nc] - 'A'] = true;
		Move(nr, nc, cnt + 1);//다음
		alphabet[board[nr][nc] - 'A'] = false;
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Move(0,0,1);//말 이동
	cout << maxCnt;//출력
	return 0;
}
