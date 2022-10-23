#include <string>
#include <vector>

using namespace std;
const int mod = 1000000007;
const int maxi = 101;
int dp[maxi][maxi];

//초기화
void init(int m, int n, vector<vector<int>> puddles){
    //웅덩이
    for(int i=0;i<puddles.size();i++) dp[puddles[i][1]][puddles[i][0]] = -1;
    //초기화
    for(int i=1;i<=n;i++){
        if(dp[i][1]==-1) break;
        dp[i][1] = 1;
    }
    for(int j=1;j<=m;j++){
        if(dp[1][j]==-1) break;
        dp[1][j] = 1;
    }
}
//등굣길
void road(int m,int n){
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(dp[i][j]==-1) continue;//장애물은 패스
            if(dp[i-1][j]!=-1 && dp[i][j-1]!=-1) dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            else if(dp[i-1][j]!=-1 && dp[i][j-1]==-1) dp[i][j] = dp[i-1][j];
            else if(dp[i-1][j]==-1 && dp[i][j-1]!=-1) dp[i][j] = dp[i][j-1];
        }
    }
}
int solution(int m, int n, vector<vector<int>> puddles) {
    init(m,n,puddles);//초기화
    road(m,n);//등굣길
    int answer = dp[n][m];
    return answer;
}
