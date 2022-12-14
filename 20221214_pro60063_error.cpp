#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Pos {//로봇 위치,방향
    int front_x, front_y, back_x, back_y;
    int width;//가로 인가?
};
int n;//board크기
const int maxi = 101;
int visit[maxi][maxi][2];//방문 시간(가로, 세로)
vector<vector<int>> board = { {0,0,0,1,1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0,0} };

int dx[4] = { 0,0,1,-1 }; int dy[4] = { -1,1,0,0 };//직선
int rwx[4] = { -1,1,-1,1 }; int rwy[4] = { -1,-1,1,1 };//회전(가로)
int rhx[4] = { -1,-1,1,1 }; int rhy[4] = { -1,1,-1,1 };//회전(세로)

//다음 지점 체크
bool chkNext(int next_first_x, int next_first_y, int next_second_x, int next_second_y,int isWidth, vector<vector<int>> board) {
    //범위 검사
    if (next_first_x < 0 || next_first_x >= n || next_first_y < 0 || next_first_y >= n) return false;
    if (next_second_x < 0 || next_second_x >= n || next_second_y < 0 || next_second_y >= n) return false;
    //둘 다 이미 방문 한 경우 제외
    if (visit[next_first_x][next_first_y][isWidth] != -1 && visit[next_second_x][next_second_y][isWidth] != -1) return false;
    //한 칸이라도 장애물이 있으면 제외
    if (board[next_first_x][next_first_y] == 1 || board[next_second_x][next_second_y] == 1) return false;
    return true;
}
//로봇 이동
int Move(vector<vector<int>> board) {
    n = board.size();
    memset(visit, -1, sizeof(visit));//초기화
    visit[0][0][0] = 0; visit[0][1][0] = 0;//초기 지점 방문 체크
    queue<Pos> q;//로봇 위치
    q.push({ 0,0,0,1,0 });

    while (!q.empty()) {
        //로봇 위치
        int first_x = q.front().front_x;
        int first_y = q.front().front_y;
        int second_x = q.front().back_x;
        int second_y = q.front().back_y;
        int isWidth = q.front().width;//가로 방향 여부
        q.pop();
        cout << "현재 위치 : " << first_x << first_y << " " << second_x << second_y <<"방향 "<<isWidth << "\n";
        //방문 완료
        if ((first_x == n - 1 && first_y == n - 1) || (second_x == n - 1 && second_y == n - 1)) {
            return visit[n - 1][n - 1][isWidth];
        }

        //회전 X
        for (int i = 0; i < 4; i++) {
            int next_first_x = first_x + dx[i]; int next_first_y = first_y + dy[i];
            int next_second_x = second_x + dx[i]; int next_second_y = second_y + dy[i];

            //범위 검사
            if (chkNext(next_first_x, next_first_y, next_second_x, next_second_y,isWidth, board) == false) continue;

            if (visit[next_first_x][next_first_y][isWidth] == -1 && visit[next_second_x][next_second_y][isWidth] == -1) {//둘다 미방문
                visit[next_first_x][next_first_y][isWidth] = visit[first_x][first_y][isWidth] + 1;
                visit[next_second_x][next_second_y][isWidth] = visit[second_x][second_y][isWidth] + 1;
            }
            else if (visit[next_first_x][next_first_y][isWidth] != -1 && visit[next_second_x][next_second_y][isWidth] == -1) {//2nd칸 미방문
                visit[next_second_x][next_second_y][isWidth] = visit[second_x][second_y][isWidth] + 1;
            }
            else if (visit[next_first_x][next_first_y][isWidth] == -1 && visit[next_second_x][next_second_y][isWidth] != -1) {//1st칸 미방문
                visit[next_first_x][next_first_y][isWidth] = visit[first_x][first_y][isWidth] + 1;
            }
            q.push({ next_first_x,next_first_y,next_second_x,next_second_y,isWidth });
        }
        //세로 방향으로 회전
        if (isWidth == 0) {
            for (int i = 0; i < 4; i++) {
                if (i < 2) {//1번축 기준
                    int next_second_x = second_x + rwx[i]; int next_second_y = second_y + rwy[i];

                    //범위 검사
                    if (chkNext(first_x, first_y, next_second_x, next_second_y,isWidth, board) == false) continue;
                    if (board[next_second_x][second_y] == 1) continue;//회전 시 장애물 충돌

                    if (visit[next_second_x][next_second_y][1] == -1) {//2nd칸 미방문
                        visit[next_second_x][next_second_y][1] = visit[second_x][second_y][isWidth] + 1;
                    }
                    q.push({ first_x,first_y,next_second_x,next_second_y,1 });
                }
                else {//2번축 기준
                    int next_first_x = first_x + rwx[i]; int next_first_y = first_y + rwy[i];
                    //범위 검사
                    if (chkNext(next_first_x, next_first_y, second_x, second_y,isWidth, board) == false) continue;
                    if(board[next_first_x][first_y] == 1) continue;//회전 시 장애물 충돌

                    if (visit[next_first_x][next_first_y][isWidth] == -1) {//1st칸 미방문
                        visit[next_first_x][next_first_y][isWidth] = visit[first_x][first_y][isWidth] + 1;
                    }
                    q.push({ next_first_x,next_first_y,second_x,second_y,1 });
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) cout << visit[i][j][0];
                    cout << "\n";
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) cout << visit[i][j][1];
                    cout << "\n";
                }
                cout << "000000000\n";
            }
        }
        else if (isWidth == 1) {//가로 방향으로 회전
            for (int i = 0; i < 4; i++) {
                if (i < 2) {//1번축 기준
                    int next_second_x = second_x + rhx[i]; int next_second_y = second_y + rhy[i];
                    //범위 검사
                    if (chkNext(first_x, first_y, next_second_x, next_second_y,isWidth, board) == false) continue;
                    if (board[second_x][next_second_y] == 1) continue;//회전 시 장애물 충돌

                    if (visit[next_second_x][next_second_y][isWidth] == -1) {//2nd칸 미방문
                        visit[next_second_x][next_second_y][isWidth] = visit[second_x][second_y][isWidth] + 1;
                    }
                    q.push({ first_x,first_y,next_second_x,next_second_y,0 });
                }
                else {//2번축 기준
                    int next_first_x = first_x + rhx[i]; int next_first_y = first_y + rhy[i];
                    //범위 검사
                    if (chkNext(next_first_x, next_first_y, second_x, second_y,isWidth, board) == false) continue;
                    if (board[first_x][next_first_y] == 1) continue;//회전 시 장애물 충돌

                    if (visit[next_first_x][next_first_y][isWidth] == -1) {//1st칸 미방문
                        visit[next_first_x][next_first_y][isWidth] = visit[first_x][first_y][isWidth] + 1;
                    }
                    q.push({ next_first_x,next_first_y,second_x,second_y,0 });
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) cout << visit[i][j][0];
                    cout << "\n";
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) cout << visit[i][j][1];
                    cout << "\n";
                }
                cout << "000000000\n";
            }
        }
    }
    return 0;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int answer = Move(board);
    cout << answer<<"\n";
	return 0;
}
