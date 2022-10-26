#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
vector<int> answer;
const int maxi = 100001;
int visit[maxi];//이전 지점

//입력
void input() {
	cin >> n >> k;
	for (int i = 0; i < maxi; i++) visit[i] = -1;
}
//이전 지점 찾기
int parent(int x) {
	answer.push_back(x);
	if (visit[x] == x) return x;
	return visit[x] = parent(visit[x]);
}
//숨바꼭질
void hide() {
	visit[n] = n;
	queue<pair<int, int>> q;
	q.push({ n,0 });//지점, 시간

	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();

		//도착
		if (x == k) {
			cout << t << "\n";
			parent(x);
		}
		//다음 지점
		if (x + 1 < maxi && visit[x + 1] == -1) {
			visit[x + 1] = x;
			q.push({ x + 1,t + 1 });
		}
		if (x - 1 >= 0 && visit[x - 1] == -1) {
			visit[x - 1] = x;
			q.push({ x - 1,t + 1 });
		}
		int next = 2 * x;
		if (next < maxi && visit[next] == -1) {
			visit[next] = x;
			q.push({ next,t + 1 });
		}
	}
}
//출력
void output() {
	for (int i = answer.size() - 1; i >= 0; i--) cout << answer[i] << " ";
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	hide();//숨바꼭질
	output();//출력
	return 0;
}
