#include <iostream>
#include <cstring>
using namespace std;

int n, l;
const int maxi = 101;
int world[maxi][maxi];//지도
bool install[maxi][maxi];//경사로 설치 여부

//입력
void input() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> world[i][j];
	}
}
//가로 탐색
bool ColCount(int i) {
	bool chkRoad = true;
	for (int j = 1; j < n; j++) {
		if (world[i][j] > world[i][j - 1]) {//이전보다 크다면
			if (world[i][j] - world[i][j - 1] != 1) {//차이가 1이 아니라면 경사로를 설치할 수 없음
				chkRoad = false;
				break;
			}
			else {
				//경사로를 설치할 수 있는가?
				for (int k = 0; k < l; k++) {
					//높이가 다르거나 범위를 초과하거나 이미설치한 곳에는 설치 불가
					if (world[i][j] - 1 != world[i][j - 1 - k] || j - 1 - k < 0 || install[i][j - 1 - k] == true) {
						chkRoad = false;
						break;
					}
				}
				//경사로 설치
				if (chkRoad) {
					for (int k = 0; k < l; k++) install[i][j - 1 - k] = true;
				}
			}
		}
		else if (world[i][j] < world[i][j - 1]) {//이전보다 작다면
			if (world[i][j - 1] - world[i][j] != 1) {//차이가 1이 아니라면 경사로를 설치할 수 없음
				chkRoad = false;
				break;
			}
			else {
				//경사로를 설치할 수 있는가?
				for (int k = 0; k < l; k++) {
					//높이가 다르거나 범위를 초과하거나 이미설치한 곳에는 설치 불가
					if (world[i][j-1]-1 != world[i][j+k] || j+k >= n || install[i][j+k] == true) {
						chkRoad = false;
						break;
					}
				}
				//경사로 설치
				if (chkRoad) {
					for (int k = 0; k < l; k++) install[i][j+k] = true;
				}
			}

		}
		else if (world[i][j] == world[i][j - 1]) continue;//같을 경우
	}

	return chkRoad;
}
//세로 탐색
bool RowCount(int j) {
	bool chkRoad = true;
	for (int i = 1; i < n; i++) {
		if (world[i][j] > world[i-1][j]) {//이전보다 크다면
			if (world[i][j] - world[i-1][j] != 1) {//차이가 1이 아니라면 경사로를 설치할 수 없음
				chkRoad = false;
				break;
			}
			else {
				//경사로를 설치할 수 있는가?
				for (int k = 0; k < l; k++) {
					//높이가 다르거나 범위를 초과하거나 이미설치한 곳에는 설치 불가
					if (world[i][j] - 1 != world[i-1-k][j] || i - 1 - k < 0 || install[i-1-k][j] == true) {
						chkRoad = false;
						break;
					}
				}
				//경사로 설치
				if (chkRoad) {
					for (int k = 0; k < l; k++) install[i-1-k][j] = true;
				}
			}
		}
		else if (world[i][j] < world[i-1][j]) {//이전보다 작다면
			if (world[i-1][j] - world[i][j] != 1) {//차이가 1이 아니라면 경사로를 설치할 수 없음
				chkRoad = false;
				break;
			}
			else {
				//경사로를 설치할 수 있는가?
				for (int k = 0; k < l; k++) {
					//높이가 다르거나 범위를 초과하거나 이미설치한 곳에는 설치 불가
					if (world[i-1][j] - 1 != world[i+k][j] || i + k >= n || install[i+k][j] == true) {
						chkRoad = false;
						break;
					}
				}
				//경사로 설치
				if (chkRoad) {
					for (int k = 0; k < l; k++) install[i+k][j] = true;
				}
			}
		}
		else if (world[i][j] == world[i-1][j]) continue;//같을 경우
	}
	return chkRoad;
}
//길의 개수 세기
void CountRoad() {
	int cnt = 0;
	//가로 탐색
	memset(install, false, sizeof(install));
	for (int i = 0; i < n; i++) cnt += ColCount(i);
	//세로 탐색
	memset(install, false, sizeof(install));
	for (int j = 0; j < n; j++) cnt += RowCount(j);

	//출력
	cout << cnt;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	CountRoad();//길의 개수 세기
	return 0;
}
