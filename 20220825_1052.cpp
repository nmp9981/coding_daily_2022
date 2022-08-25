#include <iostream>
using namespace std;

int n, k;

//1의 개수 세기
int countOne(int x) {
	if (x == 0) return 0;
	return x % 2 + countOne(x / 2);
}
//사야하는 물병의 개수
int waterCount(int n, int k) {
	int buyCount = 0;
	while (countOne(n) > k) {
		//맨뒤 비트를 없앤다.
		buyCount += (n & -n);
		n += (n & -n);
	}
	return buyCount;
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;//입력
	cout<<waterCount(n, k);//사야하는 물병의 개수
	return 0;
}
