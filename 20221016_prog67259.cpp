#include <cstring>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxi = 26;
const int inf = 900000000;
int boardSize;//맵 크기
queue<pair<pair<int,int>,int>> q;//위치, 방향
int cost[maxi][maxi][4];//가격
//동남서북
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//초기화
void init(){
    for(int i=0;i<maxi;i++){//위치
        for(int j=0;j<maxi;j++){
            for(int k=0;k<4;k++) cost[i][j][k] = inf;//방향
        }
    }
    for(int i=0;i<4;i++){
        cost[0][0][i] = 0;
        q.push({{0,0},i});
    }
}

//경주로 건설
void road(vector<vector<int>> board){
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second;
        q.pop();
        
        //다음 지점
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0 || nx>=boardSize || ny<0 || ny>=boardSize) continue;//범위조건
            if(board[nx][ny]==1) continue;//벽
            //커브
            if((dir+i)%2==1){
                if(cost[nx][ny][i]>cost[x][y][dir]+600){
                    cost[nx][ny][i]=cost[x][y][dir]+600;
                    q.push({{nx,ny},i});
                }
            }else{
                if(cost[nx][ny][i]>cost[x][y][dir]+100){
                    cost[nx][ny][i]=cost[x][y][dir]+100;
                    q.push({{nx,ny},i});
                }
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    boardSize = board.size();
    init();//초기화
    road(board);//경우의 수 구하기
    int answer = inf;
    //최종답
    for(int i=0;i<4;i++){
        if(answer>cost[boardSize-1][boardSize-1][i]) answer = cost[boardSize-1][boardSize-1][i];
    }
    return answer;
}
