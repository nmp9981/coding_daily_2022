#include <iostream>
#include <vector>
using namespace std;

int t;
vector<int> numTable[10] = {
    {10},{1},
    {6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}
};

int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int div = numTable[a % 10].size();
        if (b >= div) {
            cout << numTable[a % 10][b % div] << "\n";
        }
        else {
            cout << numTable[a % 10][b] << "\n";
        }
    }
    return 0;
}
