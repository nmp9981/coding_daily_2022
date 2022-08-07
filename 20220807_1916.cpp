#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,s,e;
const int maxi = 1001;
const int inf = 1000000001;
int A[maxi];//수열
vector<pair<int,int>> bus[maxi];//버스 노선
int cost[maxi];//출발점으로부터의 거리

//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		bus[a].push_back({ b,d });
	}
	cin >> s >> e;
}

//다익스트라
void Dijk(int start,int finish) {
	//거리 초기화
	for (int i = 0; i < maxi; i++) cost[i] = inf;

	//출발점
	cost[start] = 0;
	priority_queue<pair<int, int>>pq;//비용,노드 
	pq.push({ 0,start });

	//최소 비용 구하기
	while (!pq.empty()) {
		int fee = -pq.top().first;//비용
		int node = pq.top().second;//노드
		pq.pop();

		//더 큰비용이 오면 pass
		if (fee > cost[node]) continue;

		//다음 지점 탐색
		for (int i = 0; i < bus[node].size(); i++) {
			int nextNode = bus[node][i].first;
			int nextCost = bus[node][i].second;
			//더 작은 비용이 온다면 갱신
			if (fee + nextCost < cost[nextNode]) {
				cost[nextNode] = fee + nextCost;
				pq.push({ -cost[nextNode],nextNode });
			}
		}
	}
	cout << cost[finish];//출력
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Dijk(s,e);//다익스트라
    return 0;
}
