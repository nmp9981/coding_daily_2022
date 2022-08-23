#include <iostream>
using namespace std;

int x;
//비트 수 세기
int bitCount(int x) {
	if (x == 0) return 0;
	return x % 2 + bitCount(x / 2);
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> x;//입력
	cout<<bitCount(x);//비트 수 세기
	return 0;
}
