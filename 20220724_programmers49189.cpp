#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n;
const int maxi = 20001;
vector<int> graph[maxi];
int dist[maxi];//방문 거리
int maxDist = 0;//최대 거리

//max함수
inline int max(int x,int y){
    return x>y?x:y;
}

//그래프 세팅
void SetList(vector<vector<int>> edge){
    memset(dist,-1,sizeof(dist));//초기화
    for(int i=0;i<edge.size();i++){
        int from = edge[i][0];int to = edge[i][1];//양방향 간선
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

//bfs탐색
void bfs(){
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i=0;i<graph[node].size();i++){
            int next = graph[node][i];
            //미방문이면
            if(dist[next]!=-1) continue;
            
            dist[next] = dist[node]+1;//거리 증가
            maxDist = max(maxDist,dist[next]);//최대 거리 갱신
            q.push(next);
        }
    }
}

int CountNode(int n){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(dist[i]==maxDist) cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    SetList(edge);//그래프 세팅
    bfs();//탐색
    return CountNode(n);//노드의 개수 세기
}
