#include <iostream>
using namespace std;

int n,k,q;
const int maxi = 10001;
bool isRead[26];//읽었는가?
int notRead[maxi];//읽지 않은자
char sender[maxi];//송신자

//입력
void input(){
    cin>>n>>k>>q;
    for(int i=1;i<=k;i++) cin>>notRead[i]>>sender[i];
}
//톡
void Talk(){
    int messageQ = notRead[q];
    if(messageQ == 0) cout<<-1;//모두 읽음
    else{
        for(int i=1;i<=k;i++){
            if(notRead[i]>=messageQ){//읽지 않은 사람이 많다
                isRead[sender[i]-'A'] = true;
            }
        }
        //결과
        for(int i=1;i<n;i++){
            if(!isRead[i]) cout<<char(i+'A')<<" ";
        }
    }
}
int main()
{
    input();//입력
    Talk();//톡
    return 0;
}
