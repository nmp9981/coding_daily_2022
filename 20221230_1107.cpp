#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
const int maxi = 10;
bool breakButton[maxi];//고장 여부
vector<int> button;//작동하는 버튼
int initChannel = 100;//초기 채널
int moveCnt;//이동 횟수

//abs
inline int abs(int x) {
    return x > 0 ? x : -x;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int c; cin >> c;
        breakButton[c] = true;
    }
    //고장나지 않은 버튼
    for (int i = 0; i < 10; i++) {
        if (breakButton[i] == false) button.push_back(i);
    }
    moveCnt = abs(n - initChannel);//+,-만 사용했을 경우
}
//채널이동
void Channel(int cnt,int num) {
    if (cnt == 6) return;//최대 6자리 숫자

    //다음 숫자
    for (int i = 0; i < button.size(); i++) {
        int next = num * 10 + button[i];//다음 숫자
        moveCnt = min(moveCnt, cnt+1 + abs(next - n));//횟수 갱신
        Channel(cnt + 1, next);
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Channel(0,0);//채널이동
    cout << moveCnt;//출력
    return 0;
}
