#include <iostream>
using namespace std;

int n, m;
const int maxi = 501;
int board[maxi][maxi];//모눈 판
bool visit[maxi][maxi];//방문 여부
int ans = 0;//총합
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int a, int b) {
	return a > b ? a : b;
}
//모양
int shapeAh[4][4][2] = { {{0,0},{1,0},{2,0},{1,1}},
					{{0,0},{0,1},{0,2},{-1,1}},
					{{0,0},{1,0},{2,0},{1,-1}},
					{{0,0},{0,1},{0,2},{1,1}} };

//입력
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}
//테트로미노, 길이가 4
void tetromino(int x, int y,int cnt,int sum) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}
	//다음지점
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위초과
		if (visit[nx][ny] == true) continue;//이미 방문
		visit[nx][ny] = true;
		tetromino(nx, ny, cnt + 1, sum + board[nx][ny]);//다음 지점
		visit[nx][ny] = false;
	}
}
//ㅏ모양
int Ah(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int ahSum = 0;
		//각 모양별
		for (int j = 0; j < 4; j++) {
			int nx = x + shapeAh[i][j][0];
			int ny = y + shapeAh[i][j][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위초과
			ahSum += board[nx][ny];
		}
		ans = max(ans, ahSum);
	}
	return ans;
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	//시작지점 선택
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tetromino(i, j, 0, 0);//일반
			ans = max(ans, Ah(i,j));//ㅏ
		}
	}
	cout << ans;//출력
    return 0;
}
