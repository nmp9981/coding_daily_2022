#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, goal;
const int maxi = 1001;
const int inf = 500000001;
vector<pair<int,int>> graph[maxi];//그래프
int dist[maxi];//각 정점에서의 거리

//입력
void input() {
	cin >> n>>m>>goal;
	for (int i = 0; i < m; i++) {
		int a, b, d;//시작점, 끝점 , 거리
		cin >> a >> b >> d;
		graph[a].push_back({b,d});//단방향
	}
}
//다익스트라
int dijk(int start, int end) {
	//거리 초기화
	for (int i = 1; i <= n; i++) dist[i] = inf;

	//초기값 세팅
	dist[start] = 0;
	priority_queue<pair<int,int>> pq;//우선 순위 큐
	pq.push({0,start});//정점, 거리

	//다익스트라
	while (!pq.empty()) {
		//현재 좌표 꺼내기
		int node = pq.top().second;//정점
		int nodeDist = -pq.top().first;//거리(최솟값을 꺼내야 하므로 -)
		pq.pop();

		//더 작은 거리가 와야함
		if (nodeDist > dist[node]) continue;

		//다음 지점
		for (int j = 0; j < graph[node].size(); j++) {
			int nextNode = graph[node][j].first;//다음 정점
			int nextDist = graph[node][j].second;//node->j까지의 거리

			//다음 지점에서 더 작은 거리가 나오면 업데이트
			if (nodeDist + nextDist < dist[nextNode]) {//현재까지의 거리 + 다음 지점까지의 거리
				dist[nextNode] = nodeDist + nextDist;
				pq.push({-dist[nextNode],nextNode });//(정점, 거리)35번줄에서 음수로 넣었었다.
			}
		}
	}
	return dist[end];//최단거리
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	//집->x
	vector<int> go;//각자 집에서 x까지 가는 최단 거리
	for (int i = 1; i <= n; i++) go.push_back(dijk(i, goal));

	//x->집
	vector<int> back;//x에서 각자 집까지 가는 최단 거리
	for (int i = 1; i <= n; i++) back.push_back(dijk(goal, i));

	//가장 오래 소요되는 학생의 시간 구하기
	int times = 0;
	for (int i = 0; i < n; i++) {
		if (go[i] + back[i] > times) times = go[i] + back[i];
	}
	cout << times;//출력
	return 0;
}
