#include <stdio.h>
#include <iostream> // cout 용
#include <string> // string 쓸려고
#include <iomanip>   // 소수점 두자리 출력용
using namespace std;
#define STUDENT 5

struct Student
{
    string name;
    int id; // 학번
    int score[5]; // 5과목
    int best_score = 0;
    double avg; // 평균
};

int main() {
    struct Student student[50];

    int testcase;
    cin >> testcase;
    //scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        int student_size;
        cin >> student_size;
        //scanf("%d", &student_size);

        // 입력받기
        for (int j = 0; j < student_size; j++) {
            cin >> student[j].name >> student[j].id >> student[j].score[0] >> student[j].score[1] >> student[j].score[2] >> student[j].score[3] >> student[j].score[4];

            /* scanf과 string은 호환이 안 되는거 매우 주의!! 까먹기 쉽다.*/
            // scanf("%s %d %d %d %d %d %d", &student[j].name, &student[j].id, &student[j].score[0], &student[j].score[1], &student[j].score[2], &student[j].score[3], &student[j].score[4]);
        }

        double sum;
        int best_score;
        // 평균-최대값 구하기
        for (int j = 0; j < student_size; j++) {
            best_score = -1;

            sum = student[j].score[0] + student[j].score[1] + student[j].score[2] + student[j].score[3] + student[j].score[4];
            student[j].avg = sum / STUDENT;

            for (int k = 0; k < STUDENT; k++) {
                if (best_score < student[j].score[k]) {
                    best_score = student[j].score[k];
                    student[j].best_score = best_score;
                }
            }
        }

        // 출력
        for (int j = 0; j < student_size; j++) {
            cout << student[j].name << " " << student[j].best_score << " " << fixed << setprecision(2) << student[j].avg << endl;
        }

        if (i < testcase - 1) {
            printf("\n");
        }
    }

    return 0; // C++로 제출해야한다 지수야!!!!!!!!!!!!!!!
}
/* 소수점 출력 C언어
double avg = 94.6;

printf("%f\n",    avg);   // 94.600000   (기본 6자리)
printf("%.2f\n",  avg);   // 94.60
printf("%.4f\n",  avg);   // 94.6000
printf("%8.2f\n", avg);   //    94.60   (전체 8칸, 우측정렬)
*/

/* 소수점 출력 c++
#include <iomanip>   // 필수!

cout << fixed << setprecision(2) << avg << "\n";
*/


/* C++ string을 printf로 방법
string name = "Love";

printf("%s", name);          // 타입 불일치, 동작 보장 안 됨
printf("%s", name.c_str());  // const char*로 변환해서 전달
*/

/* C++에서 소수점 자리 출력방법
#include <iomanip>   // 필수임!!

cout << fixed << setprecision(2);
cout << alph << "\n"; //소수점 2자리

cout << defaultfloat;
cout << alph << "\n"; // 94.6  (기본값 그대로)
*/
