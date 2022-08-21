#include <iostream>
using namespace std;

int n, m, r;
const int maxi = 101;
const int inf = 200000000;
int nodeItem[maxi];//각 노드에 있는 아이템의 개수
int dist[maxi][maxi];//(i,j)까지의 최단거리

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//max
inline int max(int x, int y) {
	return x > y ? x : y;
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
//입력
void input() {
	for (int i = 1; i <= n; i++) cin >> nodeItem[i];
	for (int i = 0; i < r; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		dist[a][b] = d;//양방향
		dist[b][a] = d;
	}
}
//플로이드 알고리즘
void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
//아이템 개수 세기
void getItem() {
	int maxItemCount = 0;//얻을 수 있는 아이템 개수의 최댓값
	for (int i = 1; i <= n; i++) {
		int itemCount = 0;//i번 노드기준
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) itemCount += nodeItem[j];//수색범위 안쪽
		}
		maxItemCount = max(itemCount, maxItemCount);
	}
	cout<<maxItemCount;
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();//초기화
	input();//입력
	floyd();//플로이드 알고리즘
	getItem();//아이템 개수 세기
	return 0;
}
