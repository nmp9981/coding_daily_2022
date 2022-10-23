#include <string>
#include <vector>

using namespace std;
const int maxi = 200001;

//max
inline int max(int x,int y){
    return x>y?x:y;
}
//연속된 0의 개수
int continueZero(vector<int> stones,int mid){
    int cnt = 0;int maxCnt = 0;
    for(int i=0;i<stones.size();i++){
        if(stones[i]-mid<=0) cnt++;//0의 개수 증가
        else{
            maxCnt = max(cnt,maxCnt);
            cnt = 0;
        }
    }
    maxCnt = max(cnt,maxCnt);
    return maxCnt;
}
//징검다리 건너기
int bridge(vector<int> stones,int k){
    int start = 1;int end = 200000000;
    while(start<=end){
        int mid = (start+end)/2;//건너는 인원
        //연속된 0의 개수
        if(continueZero(stones,mid-1)>=k) end = mid-1;
        else start = mid+1;
    }
    return end;
}
int solution(vector<int> stones, int k) {
    int answer = bridge(stones,k);//징검다리 건너기
    return answer;
}
