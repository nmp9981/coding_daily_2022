#include <string>
#include <vector>
using namespace std;
bool isWin = false;//이길 수 있는가?
int maxDiff = 0;//최대 점수차
vector<int> answer;//정답
vector<int> bow;//화살 결과
vector<int> getScore;//점수를 얻을 것인가?

//더 낮은 점수에 몰려있는가?
bool LowScore(vector<int> bow,vector<int> answer){
    for(int i=10;i>=0;i--){
        if(bow[i]>answer[i]) return true;
        else if(bow[i]<answer[i]) break;
    }
    return false;
}
//결과 판단
void Judge(int n, vector<int> lion, vector<int> apach){
    int arrow = 0;//화살을 쏜 개수
    int lionScore = 0; int apachScore = 0;//점수
    for(int i=0;i<10;i++){
        if(getScore[i]==1){//라이언 득점
            lionScore+=(10-i);
            arrow+=(apach[i]+1);
        }else if(getScore[i]==0 && apach[i]>0) apachScore+=(10-i);
    }
    int diff = lionScore - apachScore;//점수차
    //라이언 승리
    if(n-arrow>=0 && diff>0 && diff>=maxDiff){
        isWin = true;
        bow.clear();
        for(int i=0;i<10;i++){
            if(getScore[i]==1) bow.push_back(apach[i]+1);
            else bow.push_back(0);
        }
        bow.push_back(n-arrow);//마지막 화살 넣기
        
        if(diff>maxDiff){//더 큰 점수차
            maxDiff = diff;
            answer = bow;
        }else if(diff==maxDiff){//동일한 점수차
            if(LowScore(bow,answer)==true) answer = bow;
        }
    }
}
//화살 쏘기
void Shoot(int cnt, int n, vector<int> info){
    //결과 분석
    if(cnt==10){
        Judge(n,getScore,info);//결과 판단
        return;
    }
    for(int i=0;i<=1;i++){
        getScore.push_back(i);
        Shoot(cnt+1,n,info);
        getScore.pop_back();
    }
}
vector<int> solution(int n, vector<int> info) {
    Shoot(0,n,info);//화살 쏘기
    if(isWin == false) answer.push_back(-1);
    return answer;
}
