#include <iostream>
using namespace std;
typedef long long ll;

ll a,b;
const int maxi = 55;
ll digitOne[maxi];//각 자릿수에서 1의 총 개수

//각 자릿수에서 1의 총 개수
void totalOneDigit() {
	digitOne[0] = 1;
	for (int i = 1; i < maxi; i++) digitOne[i] = 2 * digitOne[i - 1] + (1ll << i);
}
//1의 개수
ll countOne(ll x) {
	ll countBit = 1&x;//끝자리 1인 경우
	for (int i = maxi; i >= 1; i--) {//큰 비트부터
		if (x & (1LL << i)) {//x>=2^i
			countBit += digitOne[i - 1] + (x - (1LL << i) + 1);
			x -= (1LL << i);
		}
	}
	return countBit;
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> a>>b;//입력
	totalOneDigit();//각 자릿수에서 1의 총 개수
	cout<<countOne(b)-countOne(a-1);//1의 개수
	return 0;
}
