#include <string>
#include <vector>
using namespace std;
//유클리디언 알고리즘
int Euclidian(int x,int y){
    if(x<y) swap(x,y);
    while(y>0){
        int r = x%y;
        x = y;
        y = r;
    }
    return x;
}

int solution(vector<int> arr) {
    int answer = arr[0];
    int g = arr[0];
    for(int i=0;i<arr.size();i++){
        g = Euclidian(answer,arr[i]);//이전 최소공배수와 다음 수의 최대 공약수
        answer = (answer*arr[i])/g;
    }
    return answer;
}
