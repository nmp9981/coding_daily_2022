#include <iostream>
using namespace std;

int n;
const int maxi = 1001;
int house[maxi][3];//i번 집 j번색 비용
int cost[maxi][3];//i번 집까지 j번색으로 칠했을 때의 비용

//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) cin >> house[i][j];
    }
}
//색칠하기
void Paint() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cost[i][0] = house[i][0] + min(cost[i-1][1], cost[i - 1][2]);
            cost[i][1] = house[i][1] + min(cost[i - 1][0], cost[i - 1][2]);
            cost[i][2] = house[i][2] + min(cost[i - 1][0], cost[i - 1][1]);
        }
    }
    cout << min(cost[n][0], min(cost[n][1], cost[n][2]));
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    Paint();//색칠하기
    return 0;
}
