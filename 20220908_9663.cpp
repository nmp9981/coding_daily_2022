#include <iostream>
using namespace std;

int n,ans;
const int maxi = 16;
int selected[maxi];//각 행에 몇번열에 퀸이 있는가

//퀸을 놓을 수 있는가?
bool isNextQueen(int row) {//각 행 검사
	for (int i = 0; i < row; i++) {
		if (abs(selected[row]-selected[i]) == row-i || selected[row]==selected[i]) return false;//대각선, 같은줄
	}
	return true;
}
//n퀸 문제
void queen(int cnt) {
	//완료
	if (cnt == n) {
		ans++;//경우의 수 증가
		return;
	}
	//몇번줄에 놓을건가?
	for (int i = 0; i < n; i++) {
		selected[cnt] = i;//cnt행 i번열에 퀸이 있다.
		if (isNextQueen(cnt)) queen(cnt + 1);//놓을 수 있다면
	}
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;//입력
	queen(0);//경우의 수 세기
	cout << ans;//출력
    return 0;
}
