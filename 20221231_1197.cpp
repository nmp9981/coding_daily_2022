#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int v,e;
const int maxi = 10001;
int parent[maxi];//각 노드의 부모 노드
vector<pair<int,pair<int, int>>> graph;//그래프

//루트 노드 구하기
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
//그래프 합치기
void merge(int a, int b) {
    if (a < b) parent[b] = a;
    else parent[a] = b;
}
//초기화
void init() {
    for (int i = 0; i < maxi; i++) parent[i] = i;
}
//입력
void input() {
    cin >> v>>e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({ c,{a,b} });
    }
    sort(graph.begin(), graph.end());//거리 기준 정렬
}
//최소 스패닝 트리
void Spanning() {
    int node = 0;//연결 노드 개수
    int total = 0;//총 비용
    for (int i = 0; i < graph.size(); i++) {
        int st = graph[i].second.first;//출발
        int ed = graph[i].second.second;//도착
        int cost = graph[i].first;//비용

        int x = find(st);
        int y = find(ed);
        //루트 노드가 서로 다르다면
        if (x!=y) {
            merge(x, y);//그래프 합치기
            total += cost;
            node++;
        }
        //모두 연결
        if (node == v - 1) {
            cout << total;
            break;
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();//초기화
    input();//입력
    Spanning();//최소 스패닝 트리
    return 0;
}
