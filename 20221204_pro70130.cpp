#include <string>
#include <vector>
#include <map>
using namespace std;
map<int,int> numCnt;

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//스타 수열
int Star(vector<int> a){
    //각 숫자의 등장횟수 세기
    for(int i=0;i<a.size();i++) numCnt[a[i]]++;
    //스타 수열의 길이 구하기
    int total = 0;//최종 길이
    for(auto i:numCnt){
        if(i.second*2<=total) continue;//더 긴 수열이 이미 존재
        int len = 0;//현재 길이
        for(int j=0;j<a.size()-1;j++){
            if(a[j] != i.first && a[j+1] != i.first) continue;//교집합 여부
            if(a[j]==a[j+1]) continue;//서로 다른 원소 여부
            len+=2;j++;
        }
        total = max(total,len);//길이 갱신
    }
    return total;
}
int solution(vector<int> a) {
    int answer = -1;
    if(a.size()<2) answer = 0;
    else answer = Star(a);//스타 수열
    return answer;
}
