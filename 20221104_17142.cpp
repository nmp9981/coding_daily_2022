#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, m;
const int inf = 10000001;
const int maxi = 51;
int ans = inf;
int world[maxi][maxi];//지도
int visit[maxi][maxi];//방문 거리 
vector<pair<int, int>> virus;//바이러스
vector<pair<int, int>> activeVirus;//활성화 바이러스
//4방 탐색
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> world[i][j];
			if (world[i][j] == 2) virus.push_back({ i,j });//바이러스
		}
	}
}
//확산
int Spread() {
	//시작지점
	queue<pair<int, int>> q;
	memset(visit, -1, sizeof(visit));//초기화
	for (int i = 0; i < activeVirus.size(); i++) {
		q.push({activeVirus[i].first,activeVirus[i].second});
		visit[activeVirus[i].first][activeVirus[i].second] = 0;
	}
	int sec = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음 지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;//범위 조건
			if (visit[nx][ny] != -1) continue;//방문 조건
			if (world[nx][ny] == 1) continue;//벽

			q.push({nx,ny});
			visit[nx][ny] = visit[x][y] + 1;//빈 공간에서만 시간을 센다
			if (world[nx][ny] == 0) sec = visit[nx][ny];
		}
	}
	//확산 시간 구하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//벽이 아닌데 미방문
			if (visit[i][j] == -1 && world[i][j] != 1) return inf;
		}
	}
	return sec;
}
//활성화 바이러스
void SelectVirus(int cnt,int idx) {
	//모두 선택
	if (cnt == m) {
		ans = min(ans,Spread());//확산
		return;
	}
	//다음 바이러스
	for (int i = idx; i < virus.size(); i++) {
		activeVirus.push_back({ virus[i].first,virus[i].second });
		SelectVirus(cnt + 1, i + 1);
		activeVirus.pop_back();
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	SelectVirus(0,0);//바이러스 선택
	//출력
	if (ans == inf) cout << -1;
	else cout << ans;
	return 0;
}
