#include <string>
#include <vector>
#include <queue>

using namespace std;
const int maxi = 201;
bool visit[maxi];//방문 여부

void network(int st,vector<vector<int>> computers){
    visit[st] = true;
    queue<int> q;
    q.push(st);
    
    while(!q.empty()){
        int x = q.front();//노드 번호
        q.pop();
        
        //다음 지점
        for(int j=0;j<computers[x].size();j++){
            int next = computers[x][j];//연결 상태
            if(next==0) continue;//연결여부
            if(x==j) continue;//같은 지점
            if(visit[j]==false){//미방문인 경우
                visit[j] = true;
                q.push(j);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    //시작지점
    for(int i=0;i<n;i++){
        if(visit[i]==false){
            network(i,computers);//시작 지점
            answer++;
        }
    }
    return answer;
}
