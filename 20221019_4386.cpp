#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

//구조체
struct point {
	double x, y;
};
int n;
const int maxi = 101;
point star[maxi];//별의 좌표
vector<pair<double,pair<int,int>>> Star;//별 담기
int parent[maxi];//몇번 노드와 연결되어있는가?

//입력
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> star[i].x >> star[i].y;
		parent[i] = i;
	}
}
//루트노드 구하기
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
//거리 리스트
void DistList() {
	double distance;//거리
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			distance = sqrt(pow(star[i].x - star[j].x, 2) + pow(star[i].y - star[j].y, 2));//거리 구하기
			Star.push_back({ distance,{i,j} });
		}
	}
	sort(Star.begin(), Star.end());//거리순 정렬
}
//크루스칼
void kruskal() {
	int node = 0;//연결된 노드의 개수
	double total = 0;//총 비용
	for (int i = 0; i < Star.size(); i++) {
		double dist = Star[i].first;
		int x = Star[i].second.first;
		int y = Star[i].second.second;

		//각 노드의 루트노드
		int a = find(x);
		int b = find(y);
		if (a != b) {//안이어져 있다면 잇는다.
			parent[b] = a;
			node++;
			total += dist;
		}
		//모두 이었으면
		if (node == n - 1) {
			printf("%.2f", total);
			return;
		}
	}
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	DistList();//거리 리스트
	kruskal();//크루스칼
	return 0;
}
