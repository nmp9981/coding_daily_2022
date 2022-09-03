#include <iostream>
using namespace std;

class SinivelCap {//콧물처치용
public:
	void Take() const { cout << "콧물 치료\n"; }
};

class SneezeCap {//재채기
public:
	void Take() const { cout << "재채기\n"; }
};
class SnuffleCap {//코막힘
public:
	void Take() const { cout << "코 뚫림\n"; }
};

//콘택트 600 캡슐화
class CONTA600 {
private:
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;
public:
	void Take() const {
		scap.Take();
		zcap.Take();
		ncap.Take();
	}
};
class ColdPatient {
public:
	void TakeCONTA600(const CONTA600 &con) const { con.Take(); }
};
int main(){
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	CONTA600 con;
	ColdPatient sufferer;
	sufferer.TakeCONTA600(con);
    return 0;
}
