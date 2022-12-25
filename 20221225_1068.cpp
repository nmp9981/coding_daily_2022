#include <iostream>
#include <vector>
using namespace std;

int n;
const int maxi = 51;
int parent[maxi];//각 노드의 부모노드
bool visit[maxi];//방문 여부
int eraseNode,root;//지울 번호,루트 노드
int countLeaf = 0;//리프노드 개수
vector<int> graph[maxi];//그래프

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> parent[i];
    cin >> eraseNode;//지울 노드
}
//그래프 세팅
void SetGraph() {
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) graph[parent[i]].push_back(i);//루트노드가 아니라면
        else root = i;
    }
    graph[eraseNode].clear();//삭제
    visit[root] = true;//방문체크
}
//리프노드 세기
void CountLeaf(int node) {
    //리프노드
    if (graph[node].size() == 0) {
        countLeaf++;
        return;
    }
    //다음 지점
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];//다음 노드
        if (visit[next] == false) {//미방문이면
            visit[next] = true;
            CountLeaf(next);
            visit[next] = false;
        }
    }
}
//출력
void output() {
    if (graph[parent[eraseNode]].size() >= 2) countLeaf -= 1;
    cout << countLeaf;//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    SetGraph();//그래프 세팅
    if (eraseNode == root) cout << 0;//루트 노드 지울 경우
    else {
        CountLeaf(root);//리프노드 세기
        output();//출력
    }
    return 0;
}
