#include <iostream>
using namespace std;

int n;
const int maxi = 10001;
int dice[maxi][6];
int ans = 0;

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) cin >> dice[i][j];
	}
}

//밑면
int BottomSide(int upSide) {
	if (upSide == 0 || upSide == 5) {
		return 5 - upSide;
	}
	else if (upSide == 1 || upSide == 3) {
		return 4 - upSide;
	}
	else if (upSide == 2 || upSide == 4) {
		return 6 - upSide;
	}
}

//주사위
int Dice(int index) {
	int upSide = index;//윗면 번호
	int diceSum = 0;//총합
	for (int i = 0; i < n; i++) {
		int downSide = BottomSide(upSide);//밑면 번호
		int downDigit = dice[i][downSide];//밑면 숫자
		int diceNum = 0;//주사위 눈
		for (int j = 0; j < 6; j++) {
			if (j != downSide && j != upSide) diceNum = max(diceNum, dice[i][j]);
		}
		diceSum += diceNum;//누적
		//다음 윗면
		if (i < n - 1) {
			for (int j = 0; j < 6; j++) {
				if (downDigit == dice[i + 1][j]) upSide = j;
			}
		}
	}
	return diceSum;
}

int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	for (int i = 0; i < 6; i++) ans = max(ans,Dice(i));//윗면 숫자
	cout << ans;//출력
    return 0;
}
