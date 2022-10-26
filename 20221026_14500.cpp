#include <iostream>
#include <queue>
using namespace std;

int n, m;
const int maxi = 501;
int board[maxi][maxi];//보드판
bool visit[maxi][maxi];//방문 여부
int blockSum = 0;//총합
bool dir[4];//고른 방향 여부
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

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
//테트로미노 , 길이가 4인 dfs탐색
void tetromino(int x,int y,int cnt,int sum) {
	//길이가 4인경우
	if (cnt == 4) {
		blockSum = max(sum, blockSum);
		return;
	}
	//다음 지점
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visit[nx][ny] == true) continue;

		visit[nx][ny] = true;
		tetromino(nx, ny, cnt + 1, sum + board[nx][ny]);//다음 지점
		visit[nx][ny] = false;
	}
}

//ㅏ모양
void AH(int x, int y) {//중심좌표
	int AhSum = board[x][y];
	int Ahcnt = 0;
	//가능한 지점 개수
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		AhSum += board[nx][ny];
		Ahcnt++;
	}
	//ㅏ가 만들어지는가?
	if (Ahcnt == 3) blockSum = max(blockSum, AhSum);
	else if (Ahcnt == 4) {
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			blockSum = max(blockSum, AhSum - board[nx][ny]);
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tetromino(i,j,0,0);//테트로미노
			AH(i, j);//ㅏ모양 중심좌표
		}
	}
	cout << blockSum;//출력
	return 0;
}
