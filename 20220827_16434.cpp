#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

//구조체
struct stage {
	int type; ll attack; ll hp;
};
ll n,playerAttack;
vector<stage> dungeon;

//max
inline ll max(ll x, ll y) {
	return x > y ? x : y;
}
//min
inline ll min(ll x, ll y) {
	return x > y ? y : x;
}
//입력
void input() {
	cin >> n >> playerAttack;
	for (int i = 0; i < n; i++){
		int ti;
		ll ai, hi;
		cin >> ti >> ai >> hi;
		dungeon.push_back({ ti,ai,hi });
	}
}
//던전 공략
void Play() {
	ll minHP = 0;//최소 HP;
	ll decreaseHP = 0;//감소한 HP
	for (int i = 0; i < n; i++) {
		if (dungeon[i].type == 1) {
			ll attackCount = (dungeon[i].hp-1) / playerAttack;
			decreaseHP += attackCount * dungeon[i].attack;
			minHP = max(minHP, decreaseHP);
		}
		else if (dungeon[i].type == 2) {
			playerAttack += dungeon[i].attack;
			decreaseHP = max(0ll, decreaseHP - dungeon[i].hp);
		}
	}
	cout << minHP+1;//출력, HP 0이면 사망
}
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	Play();//던전 공략
    return 0;
}
