#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m,t;
const int maxi = 10001;
const int caseMaxi = 21;
const int inf = 99999999;
int coin[maxi];//동전 종류
int caseNum[caseMaxi][maxi];//경우의 수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//입력
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> coin[i];
    cin >> m;
}
//초기화
void init() {
    memset(caseNum, 0, sizeof(caseNum));
    memset(coin, 0, sizeof(coin));
}

//지불 방법
void Pay() {
    //1번째 동전만 사용
    for (int i = 0; i <= m; i++) {
        if (i % coin[1] == 0) caseNum[1][i] = 1;
    }
    //2번째 동전부터
    for (int i = 2; i <= n; i++) {//i번째 동전까지
        for (int j = 0; j <= m; j++) {//현재 총액
            if (coin[i] > j) caseNum[i][j] = caseNum[i - 1][j];//돈 부족
            else caseNum[i][j] = caseNum[i - 1][j] + caseNum[i][j - coin[i]];//coin[i]를 사용한 경우 + 사용 X 경우
        }
    }
    cout << caseNum[n][m]<<"\n";//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        init();//배열 초기화
        input();//입력
        Pay();//아이템 습득
    }
    return 0;
}
