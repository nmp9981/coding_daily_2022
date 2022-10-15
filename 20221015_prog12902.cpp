#include <string>
#include <vector>
typedef long long ll;
using namespace std;
const int maxi = 5001;
const ll mod = 1000000007;
ll dp[maxi];//타일 채우는 경우의 수

//타일 채우기
void tile(){
    dp[2] = 3;dp[0] = 1;
    for(int i=4;i<maxi;i++){
        dp[i] = 3*dp[i-2];
        for(int j=i-4;j>=0;j-=2) dp[i]+=(2*dp[j]);
        dp[i]%=mod;
    }
}
int solution(int n) {
    ll answer=0;
    tile();//타일 채우기
    if(n%2==0) answer = dp[n];//n이 짝수일때만 채울 수 있다.
    return answer;
}
