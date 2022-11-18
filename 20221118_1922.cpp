#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 1001;
vector<pair<int, pair<int, int>>> graph;//그래프
int parent[maxi];//각 노드의 루트 노드

//min
inline int min(int x, int y) {
	return x > y ? y : x;
}
//루트노드 찾기
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
//합체
void merge(int x, int y) {
	if (x > y) parent[x] = y;
	else parent[y] = x;
}
//입력
void input() {
	cin >> n>>m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		graph.push_back({ d,{a,b} });
	}
	for (int i = 1; i <= n; i++) parent[i] = i;//부모 노드 초기화
	sort(graph.begin(), graph.end());//비용순 정렬
}
//네트워크 연결
void Connect() {
	int node = 0;//연결 노드 수
	int total = 0;//총 비용
	for (int i = 0; i < graph.size(); i++) {
		int cost = graph[i].first;
		int st = graph[i].second.first;
		int end = graph[i].second.second;

		//루트노드가 서로 다르면 연결
		st = find(st);
		end = find(end);
		if (st!= end) {
			merge(st, end);//합체
			node++;//노드 증가
			total += cost;
		}
		//연결 완료
		if (node == n - 1) break;
	}
	cout << total;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	input();//입력
	Connect();//연결
	return 0;
}
