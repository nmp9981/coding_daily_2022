#include <iostream>
#include <vector>
using namespace std;

int n,m,tru,human;
const int maxi = 51;
vector<int> know;//진실을 아는 자
vector<int> people[maxi];//파티에 오는 사람
int root[maxi];//각 노드의 루트 노드

//루트 노드 찾기
int find(int x) {
	if (root[x] == x) return x;
	return root[x] = find(root[x]);
}
//합치기(루트와 합치기)
void merge(int a, int b) {
	a = find(a);b = find(b);
	root[b] = a;//왼쪽과 연결
}
//입력
bool input() {
	cin >> n>>m;
	cin >> tru;
	for (int i = 1; i <= n; i++) root[i] = i;//초기화
	//진실을 아는자
	for (int i = 0; i < tru; i++) {
		int tr;cin >> tr;
		know.push_back(tr);
	}
	//파티에 오는 사람 
	for (int i = 0; i < m; i++) {
		cin >> human;
		for (int j = 0; j < human; j++) {
			int x;cin >> x;
			people[i].push_back(x);
		}
	}
	if (tru == 0) return false;//진실을 아는자가 존재 하는가?
	return true;
}

//파티 검사
void Party() {
	//그래프 연결
	for (int i = 0; i < m; i++) {
		int first = people[i][0];
		for (int j = 1; j < people[i].size(); j++) merge(first, people[i][j]);//합치기
	}
	
	int cnt = 0;//파티의 개수
	for (int i = 0; i < m; i++) {
		bool flag = true;//파티 참여 가능한가?
		for (int j = 0; j < people[i].size(); j++) {
			if (flag == false) break;
			int cust = find(people[i][j]);
			for (int k = 0; k < know.size(); k++) {//진실을 아는 자가 있는가?
				if (cust == find(know[k])) {
					flag = false;
					break;
				}
			}
		}
		if (flag) cnt++;//참여 가능
	}
	cout << cnt;
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	//진실을 아는자가 존재하는가?
	if (input() == false) cout << m;
	else Party();//파티의 개수
	return 0;
}
