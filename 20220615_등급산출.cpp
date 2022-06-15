#include <iostream>
#include <cstring>
using namespace std;

//제목
void title() {
    cout << "이름 원점수 등급 백분위\n";
}

//학생 클래스
class Student {
private:
    char* name;//이름
    int score;//원점수
    int cut_score[10];//등급컷
    int cut_percentage[10];//백분위 등급컷
    int grade;//등급
    int percentage;//백분위

public:
    Student(const char* s);//생성자
    ~Student();//소멸자

    void set_grade();//등급컷 설정
    void result_grade(int sco);//등급 산출
    void print() const;//출력
};

//생성자
Student::Student(const char* s) {
    name = new char[strlen(s) + 1];
    strcpy(name, s);

    memset(cut_score, 0, sizeof(cut_score));
    memset(cut_percentage, 0, sizeof(cut_percentage));
    score = 100;
    grade = 1;
    percentage = 100;
}

//등급산출
void Student::result_grade(int sco) {
    score = sco;
    //백분위 산출
    for (int i = 1; i <= 9; i++) {
        if (score >= cut_score[i]) {
            percentage = cut_percentage[i]+(cut_percentage[i-1]-cut_percentage[i])*(score - cut_score[i]) / (cut_score[i - 1] - cut_score[i]);
            break;
        }
    }
    //결과
    if (percentage >= 96) grade = 1;
    else if (percentage >= 89 && percentage < 96) grade = 2;
    else if (percentage >= 77 && percentage < 89) grade = 3;
    else if (percentage >= 60 && percentage < 77) grade = 4;
    else if (percentage >= 40 && percentage < 60) grade = 5;
    else if (percentage >= 23 && percentage < 39) grade = 6;
    else if (percentage >= 11 && percentage < 23) grade = 7;
    else if (percentage >= 4 && percentage < 11) grade = 8;
    else grade = 9;
}

//등급컷 설정
void Student::set_grade() {
    cut_score[0] = 100; cut_percentage[0] = 100;
    cut_score[1] = 92; cut_percentage[1] = 96;
    cut_score[2] = 80; cut_percentage[2] = 89;
    cut_score[3] = 72; cut_percentage[3] = 77;
    cut_score[4] = 58; cut_percentage[4] = 60;
    cut_score[5] = 40; cut_percentage[5] = 40;
    cut_score[6] = 28; cut_percentage[6] = 23;
    cut_score[7] = 20; cut_percentage[7] = 11;
    cut_score[8] = 13; cut_percentage[8] = 4;
    cut_score[9] = 0; cut_percentage[9] = 0;
}

//출력
void Student::print() const {
    cout << name << " " << score << " " << grade << " " << percentage << "\n";
}

//소멸자
Student::~Student() {
    if (name != NULL) delete[] name;
}

int main() {
    
    int n;
    cin>>n;
    Student student("INTJ");
    student.set_grade();
    student.result_grade(n);
    student.print();

    return 0;
}
