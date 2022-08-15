#include <iostream>
using namespace std;

struct point {
	int x, y;
};

point rect[4];//직사각형

//입력
void input() {
	for (int i = 0; i < 3; i++) cin >> rect[i].x >> rect[i].y;
}

//직사각형 점 구하기
void RectPoint() {
	rect[3].x = rect[0].x ^ rect[1].x ^ rect[2].x;
	rect[3].y = rect[0].y ^ rect[1].y ^ rect[2].y;
	cout << rect[3].x <<" " << rect[3].y << "\n";
}
int main()
{
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	input();//입력
	RectPoint();//직사각형 점 구하기
	return 0;
}
