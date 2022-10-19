#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> ramen;//라면

//입력
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;//기한, 보상
		ramen.push_back({ a,b });
	}
	sort(ramen.begin(), ramen.end());//기한 기준으로 정렬
}
//과제
void Task() {
	int total = 0;//총합
	priority_queue<int ,vector<int>, greater<int>> pq;//최소 힙
	for (int i = 0; i < n; i++) {
		int deadline = ramen[i].first;//기한
		int xp = ramen[i].second;//보상

		pq.push(xp);//넣기
		//용량초과
		if (pq.size() > deadline) pq.pop();
	}
	//총합
	while(!pq.empty()) {
		total += pq.top();
		pq.pop();
	}
	cout << total;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Task();//과제 수행
	return 0;
}
