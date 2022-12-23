#include <iostream>
#include <vector>
using namespace std;

const int maxi = 9;
int board[maxi][maxi];//스도쿠 보드
vector<pair<int, int>> blank;//빈칸

//입력
void input() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) blank.push_back({ i,j });//빈칸
        }
    }
}
//출력
void output() {
    for (int i = 0; i < maxi; i++) {
        for (int j = 0; j < maxi; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
//상자 조건
bool box(int x, int y,int n) {
    int sx = 3*(x / 3);int sy =3*(y / 3);//시작 위치
    for (int i = sx; i < sx + 3; i++) {
        for (int j = sy; j < sy + 3; j++) {
            if (board[i][j] == n) return false;//이미 해당 숫자 존재
        }
    }
    return true;
}
//행조건
bool row(int x, int y, int n) {
    for (int j = 0; j < maxi; j++) {
        if (board[x][j] == n) return false;//이미 해당 숫자 존재
    }
    return true;
}
//열조건
bool col(int x, int y, int n) {
    for (int i = 0; i < maxi; i++) {
        if (board[i][y] == n) return false;//이미 해당 숫자 존재
    }
    return true;
}
//스도쿠 풀이
void solve(int cnt) {
    //모두 채움
    if (cnt == blank.size()) {
        output();//출력
        exit(0);//종료
    }
    //위치
    int nx = blank[cnt].first;
    int ny = blank[cnt].second;
    //빈칸 채우기
    for (int k = 1; k <= 9; k++) {
        if (box(nx,ny,k) && row(nx,ny,k) && col(nx,ny,k)) {//조건을 모두 만족
            board[nx][ny] = k;
            solve(cnt + 1);
            board[nx][ny] = 0;
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    solve(0);//풀이
    return 0;
}
