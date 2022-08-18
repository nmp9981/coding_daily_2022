#include <iostream>
using namespace std;
typedef unsigned long long ull;

ull n,b;
int primeCount;
ull num[3] = { 2,7,61 };

//입력
void input() {
	ull a;
	cin >> a;
	b = 2 * a + 1;
}

//제곱
ull Pow(ull x, ull y, ull mod) {
	ull ret = 1;
	x %= mod;
	while (y) {
		if (y % 2 == 1) ret = (ret * x) % mod;
		y /= 2;
		x = (x * x) % mod;
	}
	return ret;
}

//소수인가?
bool IsPrime(ull x,ull a) {
	if (a % n == 0) return true;//소수
	ull k = x - 1;
	while (1) {
		ull temp = Pow(a, k, x);
		if (temp == n - 1) return true;
		if (k % 2 == 1) return (temp == 1 || temp == n - 1);
		k /= 2;
	}
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	while (n--) {
		input();//입력
		for (int i = 0; i < 3; i++) {
			//소수인가?
			if (IsPrime(b, num[i])) primeCount++;
		}
	}
	cout << primeCount;//출력
    return 0;
}
