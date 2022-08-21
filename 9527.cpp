#include <iostream>
using namespace std;
typedef long long ll;

ll a, b;

//1의 개수 세기
ll f(ll x) {
	ll countOne = 0;//1의 총 개수
	ll pattern = 2;//패턴의 길이
	while (pattern <= x) {
		countOne += (x / pattern)*(pattern/2);
		if ((x % pattern) >= (pattern / 2)) countOne += ((x % pattern) - (pattern / 2) + 1);
		pattern *= 2;
	}
	countOne += ((x % pattern) - pattern / 2 + 1);//맨 앞자리수
	return countOne;
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;
	cout << f(b) - f(a - 1);
	return 0;
}
