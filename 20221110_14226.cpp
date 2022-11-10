#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int s,add;
const int maxi = 1001;
bool visit[maxi][maxi];//방문 여부(현재 개수, 추가 개수)

//입력
void input() {
	cin >> s;
	memset(visit, sizeof(visit), false);//초기화
}

//이모티콘 추가
void imog() {
	queue<pair<int,pair<int, int>>> q;
	q.push({ 0,{ 1,0 } });
	visit[1][0] = true;

	while (!q.empty()) {
		int cnt = q.front().first;//시간 최솟값
		int x = q.front().second.first;//현재 개수
		int add = q.front().second.second;//추가 개수
		q.pop();

		//완료
		if (x == s) {
			cout << cnt;
			return;
		}
		//복사
		if (visit[x][x] == false && x<maxi) {//범위내에 들고 미방문
			visit[x][x] = true;
			q.push({ cnt + 1,{x ,x} });
		}
		//붙여넣기
		if (x+add<maxi && visit[x +add][add] == false) {
			visit[x +add][add] = true;
			q.push({ cnt + 1,{x +add,add} });
		}
		//삭제
		if (x>=1 && visit[x - 1][add] == false) {
			visit[x - 1][add] = true;
			q.push({ cnt + 1,{x - 1,add} });
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	imog();//현재 개수, 추가 개수
	return 0;
}
