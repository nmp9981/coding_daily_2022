#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n;
const int maxi = 6;
ll dice[maxi];//주사위
ll sum_one = 0;//주사위 총합
int diceVertex[8][3] = {//꼭짓점 목록
    {0,3,4},{0,3,1},{0,4,2},{0,1,2},
    {5,1,3},{5,3,4},{5,1,2},{5,4,2}
};
int diceEdge[12][2] = {//모서리 목록
    {0,1},{0,2},{0,3},{0,4},
    {3,4},{3,1},{1,2},{2,4},
    {1,5},{2,5},{3,5},{4,5}
};

//입력
void input() {
    cin >> n;
    int big = 0;
    for (int i = 0; i < maxi; i++) {
        cin >> dice[i];
        sum_one += dice[i];
        if (big < dice[i]) big = dice[i];//가장 큰 수 구하기
    }
    sum_one -= big;//가장 큰수를 제외한 나머지의 합
}
//주사위 합
ll SumDice() {
    //모서리
    ll edge = 101;
    for (int i = 0; i < 12; i++) {
        if (edge > dice[diceEdge[i][0]] + dice[diceEdge[i][1]]) edge = dice[diceEdge[i][0]] + dice[diceEdge[i][1]];
    }
    //꼭짓점
    ll vertex = 151;
    for (int i = 0; i < 8; i++) {
        if (vertex > dice[diceVertex[i][0]] + dice[diceVertex[i][1]] + dice[diceVertex[i][2]]) {
            vertex = dice[diceVertex[i][0]] + dice[diceVertex[i][1]] + dice[diceVertex[i][2]];
        }
    }
    //면
    ll side = 51;
    for (int i = 0; i < maxi; i++) {
        if (side > dice[i]) side = dice[i];
    }
    //총합(꼭짓점 4개, 모서리 4+8*(n-2)개, 면 4*(n-2)+5*(n-2)*(n-2)개
    ll sum = vertex * 4 + edge * (4+8*(n-2))+side*(4*(n-2)+5*(n-2)*(n-2));
    return sum;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    if (n == 1) cout << sum_one;//주사위가 1개일 때
    else cout<<SumDice();//주사위 합
    return 0;
}
