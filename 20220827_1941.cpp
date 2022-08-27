#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxi = 5;
string classroom[maxi];//교실
bool visit[maxi][maxi];//방문
bool selected[25];//선택 여부
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int caseNum = 0;//경우의 수

//입력
void input() {
	for (int i = 0; i < maxi; i++) cin >> classroom[i];
}
//솜파가 더 많은가?
bool isSom() {
	int cntSom = 0;
	for (int i = 0; i < 25; i++) {
		int nx = i / 5;
		int ny = i % 5;
		if (selected[i] == true) {
			if (classroom[nx][ny] == 'S') cntSom++;
		}
		if (cntSom >= 4) return true;
	}
	return false;
}
//연결되어 있는가?
bool isConnect() {
	int cnt = 1;
	queue < pair<int, int> > q;
	memset(visit, false, sizeof(visit));
	//첫지점
	for (int i = 0; i < 25; i++) {
		if (selected[i] == true) {
			q.push({ i/5,i%5 });
			visit[i / 5][i % 5] = true;
			break;
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//다음 지점
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= maxi || ny < 0 || ny >= maxi) continue;//범위내에 들고
			if (visit[nx][ny] == true || selected[5*nx+ny]==false) continue;//미방문인가?
			visit[nx][ny] = true;
			cnt++;
			q.push({ nx,ny });
		}
	}
	if (cnt == 7) return true;
	else return false;
}
//파티
void party(int index,int cnt) {
	//파티 결성
	if (cnt == 7) {
		if (isSom()) {
			if (isConnect()) {//연결되어있고 솜파인가?
				caseNum++;
			}
		}
		return;
	}
	for (int i = index; i <25;i++) {
		if (selected[i] == false) {//아직 선택 x
			selected[i] = true;
			party(i+1, cnt + 1);//다음 지점
			selected[i] = false;
		}
	}
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력택
	party(0,0);//학생선택
	cout << caseNum;
    return 0;
}
