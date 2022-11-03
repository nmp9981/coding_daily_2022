#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m,ans;
const int maxi = 51;
string world[maxi];//지도
int visit[maxi][maxi];//방문 거리
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) cin >> world[i];
}
//보물탐색
int search(int i, int j) {
	memset(visit, -1, sizeof(visit));//초기화
	visit[i][j] = 0;
	int dist = 0;//가장 먼 거리
	queue<pair<int, int>> q;//위치 체크
	q.push({ i,j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음 지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위조건
			if (visit[nx][ny] != -1) continue;//방문조건
			if (world[nx][ny] == 'W') continue;//바다인가?

			q.push({ nx,ny });
			visit[nx][ny] = visit[x][y] + 1;//다음 지점
			dist = max(dist, visit[nx][ny]);//최장 거리 갱신
		}
	}
	return dist;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	//시작지점 찾기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (world[i][j] == 'L') ans = max(ans, search(i, j));//육지이면, 최단 거리 갱신
		}
	}
	cout << ans;//출력
	return 0;
}
