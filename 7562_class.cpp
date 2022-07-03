#include<iostream>
#include<array>
#include<queue>
using namespace std;

struct Move {
	Move(int _x, int _y, int _depth) :
		x(_x), y(_y), depth(_depth) {}

	int x;
	int y;
	int depth;
};

class Knight {
public:
	Knight() {}

	void input();//입력
	int bfs();//초기화
private:
	static const int maxi = 304;

	array<array<bool, maxi>, maxi> visited {};//2차원 배열
	int l;//체스판의 크기
	int cx, cy, tx, ty;//현재위치, 목표위치
	array<int, 8> dx{ -2,-1,1,2,2,1,-1,-2 };
	array<int, 8> dy{ 1,2,2,1,-1,-2,-2,-1 };
};

//입력
void Knight::input() {
	cin >> l;//크기
	cin >> cx >> cy >> tx >> ty;//현재 말의 위치
	
	l += 4;
	cx += 2; cy += 2; tx += 2; ty += 2;
	
	//방문기록
	for (int i = 0; i < l; i++) {
		visited[i][0] = true;
		visited[i][1] = true;
		visited[i][l-1] = true;
		visited[i][l-2] = true;

		visited[0][i] = true;
		visited[1][i] = true;
		visited[l-1][0] = true;
		visited[l-2][0] = true;
	}
}
//bfs탐색
int Knight::bfs() {
	//목표도달
	if (cx == tx && cy == ty) return 0;

	queue<Move> q;
	q.emplace(cx, cy, 0);
	visited[cx][cy] = true;

	while (!q.empty()) {
		Move cur = q.front();
		q.pop();
		//인접노드 검사
		for (size_t i = 0; i < dx.size(); i++) {
			Move next(cur.x + dx[i], cur.y + dy[i], cur.depth + 1);

			//이미 방문, 범위 벗어남
			if (visited[next.x][next.y]) continue;

			//목표도착
			if (next.x == tx && next.y == ty) {
				int retVal = next.depth;
				return retVal;
			}
			else {
				visited[next.x][next.y] = true;
				q.emplace(next.x, next.y, next.depth);
			}
		}
	}
	return -1;//탐색 실패
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;//테스트 케이스
	cin >> t;
	while (t--) {
		Knight knight;//기사 클래스

		knight.input();
		cout << knight.bfs() << "\n";
	}
	return 0;
}
