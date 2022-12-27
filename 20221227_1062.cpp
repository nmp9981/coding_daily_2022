#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n,k;
const int maxi = 51;
const int alphaMaxi = 26;
string word[maxi];//단어
bool alpha[alphaMaxi];//알파벳 사용 여부
int canRead = 0;//읽을 수 있는 단어의 수

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n>>k;
    for (int i = 0; i < n; i++) cin >> word[i];
    //필수 글자
    alpha[0] = true;//a
    alpha[2] = true;//c
    alpha[8] = true;//i
    alpha[13] = true;//n
    alpha[19] = true;//t
}
//테스트
int Test() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool isCan = true;
        for (int j = 4; j < word[i].size() - 4; j++) {
            //읽을 수 없다면
            if (alpha[word[i][j]-'a'] == false) isCan = false;
        }
        if (isCan == true) cnt++;//읽을 수 있다면
    }
    return cnt;
}
//가르침
void Teach(int idx, int wordCnt) {
    //배우기 완료
    if (wordCnt == k - 5) {
        canRead = max(canRead, Test());//단어 개수
        return;
    }
    //다음 글자
    for (int i = idx; i < alphaMaxi; i++) {
        if (alpha[i] == false) {//미선택 글자
            alpha[i] = true;//선택
            Teach(i + 1, wordCnt + 1);
            alpha[i] = false;
        }
    }
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    if (k < 5) cout << 0;//불가능
    else if (k >= 5) {
        Teach(1,0);//단어 배우기
        cout << canRead;//출력
    }
    return 0;
}
