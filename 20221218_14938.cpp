#include <iostream>
#include <vector>
using namespace std;

int n, m, r;
const int maxi = 101;
const int inf = 99999999;
int item[maxi];//i번 노드 아이템 개수
int dist[maxi][maxi];//i->j최단 거리

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
    for (int i = 1; i <= n; i++) cin >> item[i];
    for (int i = 0; i < r; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        dist[a][b] = d;//양방향 그래프
        dist[b][a] = d;
    }
}
//초기화
void init() {
    cin >> n >> m >> r;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = inf;
        }
    }
}

//아이템 습득
void GetItem() {
    for (int k = 1; k <= n; k++) {//경유 지점
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int maxGet = 0;//최대 아이템 개수
    for (int i = 1; i <= n; i++) {//시작 지점
        int amount = 0;//얻는 아이템의 수
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m) amount += item[j];//수색범위 내 득템
        }
        maxGet = max(maxGet, amount);//갱신
    }
    cout << maxGet;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();//배열 초기화
    input();//입력
    GetItem();//아이템 습득
    return 0;
}
