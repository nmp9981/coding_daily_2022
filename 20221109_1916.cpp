#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m,start,ed;
const int maxi = 1001;
const int inf = 500000001;
vector<pair<int, int>> graph[maxi];//그래프
int cost[maxi];//i번에서의 거리

//max
inline int max(int x, int y) {
	return x > y ? x : y;
}
//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });//정점, 비용
	}
	cin >> start >> ed;
}
//다익스트라
int dijk(int start,int ed) {
	//초기화
	for (int i = 1; i <= n; i++) cost[i] = inf;
	cost[start] = 0;
	priority_queue<pair<int, int>> pq;//우선순위 큐
	pq.push({ 0,start });//비용, 정점

	while (!pq.empty()) {
		int fee = -pq.top().first;//비용(최대힙이니 -)
		int node = pq.top().second;//정점
		pq.pop();

		//더 작은 비용이 나올때만
		if (fee > cost[node]) continue;

		//다음 지점
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i].first;
			int nodeFee = graph[node][i].second;

			//비용의 합이 더 작을 경우에만 갱신
			if (fee + nodeFee < cost[next]) {
				cost[next] = fee + nodeFee;
				pq.push({ -cost[next],next });
			}
		}
	}
	return cost[ed];
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	cout<<dijk(start, ed);//start->ed까지의 최단거리
	return 0;
}
