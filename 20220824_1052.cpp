#include <iostream>
using namespace std;

int n,k;

//1의 개수
int addWater(int x) {
	if (x == 0) return 0;
	return x % 2 + addWater(x / 2);
}
//물병 나누기
int water(int n,int k) {
	int buyWater = 0;
	//1의 개수로 풀이
	while (1) {
		if (addWater(n) <= k) return buyWater;
		else {
			n++;
			buyWater++;//물병 개수 증가
		}
	}
	return buyWater;
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n>>k;//입력
	cout<<water(n,k);//물병 나누기
	return 0;
}
