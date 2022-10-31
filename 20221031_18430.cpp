#include <iostream>
using namespace std;

int n, m,attack;
const int maxi = 5;
int board[maxi][maxi];//보드판
bool visit[maxi][maxi];//방문여부
//동남서북
int dr[4] = { 1,1,-1,-1 };
int dc[4] = { 1,-1,-1,1 };

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}
}
//무기 만들기
void MakeWeapon(int r, int c, int sum) {
	//다음 행
	if (c == m) {
		r++; c = 0;
	}
	//종료
	if (r == n) {
		attack = max(attack, sum);
		return;
	}
	//4방 탐색
	if (visit[r][c] == false) {//미방문 지점만
		for (int k = 0; k < 4; k++) {
			int nc = c + dc[k];
			int nr = r + dr[k];

			if (nc >= m || nc < 0 || nr >= n || nr < 0) continue;//범위조건
			if (visit[nr][c] || visit[r][nc]) continue;//방문조건
			//방문체크
			visit[r][c] = true;
			visit[nr][c] = true;
			visit[r][nc] = true;

			int nextSum = sum + 2 * board[r][c] + board[nr][c] + board[r][nc];//누적
			MakeWeapon(r, c + 1, nextSum);//다음 지점

			//체크해제
			visit[r][c] = false;
			visit[nr][c] = false;
			visit[r][nc] = false;
		}
	}
	//이미 재료가 소진되면 다음으로
	MakeWeapon(r, c + 1, sum);
}

int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	if (n == 1 || m == 1) cout << 0;//만들 수 없음
	else {
		MakeWeapon(0, 0, 0);//i,j에서의 누적 무기공격력
		cout << attack;
	}
	return 0;
}
