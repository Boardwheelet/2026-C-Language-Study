# 1424번 - 학생 성적 관리 시스템

## 📋 문제 정보

- **사이트** : ASCODE
- **분류** : 구조체, 배열
- **제한** : 시간 1초 / 메모리 128MB
- **링크** : http://ascode.org/problem.php?id=1424

---

## 📝 문제 설명

N명의 학생 데이터(이름, 학번, 5과목 점수)를 입력받아, 각 학생의 **최고 점수**와 **평균(소수점 둘째 자리)**을 출력한다. 테스트케이스 사이에는 빈 줄 하나.

---

## 📥 입력

```
T (테스트케이스 수, 1 ≤ T ≤ 20)
각 케이스: N (학생 수, 1 ≤ N ≤ 50)
이름(최대 10자) 학번 점수1 점수2 점수3 점수4 점수5
```

## 📤 출력

```
이름 최고점수 평균(소수점 둘째 자리)
테스트케이스 사이 빈 줄 하나 (마지막 케이스 뒤에는 없음)
```

---

## 💡 예제

| 입력 | 출력 |
|------|------|
| `Love 31921 78 69 56 76 55` | `Love 78 66.80` |
| `Tom 12345 100 87 96 99 91` | `Tom 100 94.60` |
| `Jeniffer 32123 98 78 97 78 87` | `Jeniffer 98 87.60` |
| `John 14321 78 67 76 91 88` | `John 91 80.00` |

---

## 🧠 풀이 핵심

- **구조체 배열** 사용: `Student student[50]`
- 평균 = (5과목 합산) / 5.0 → `double`로 저장
- 최고 점수 = `best_score = -1`로 초기화 후 5과목 순회
- 소수점 출력: `cout << fixed << setprecision(2)`
- 빈 줄: **마지막 케이스 제외**하고 출력 → `if (i < testcase - 1) printf("\n")`

```c
// 핵심 스니펫
student[j].avg = sum / STUDENT;  // STUDENT = 5 (매크로)

if (best_score < student[j].score[k])
    best_score = student[j].score[k];

cout << fixed << setprecision(2) << student[j].avg;
```

---

## ✅ 내 코드

```cpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define STUDENT 5

struct Student
{
    string name;
    int id;
    int score[5];
    int best_score = 0;
    double avg;
};

int main() {
    struct Student student[50];

    int testcase;
    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        int student_size;
        cin >> student_size;

        for (int j = 0; j < student_size; j++) {
            cin >> student[j].name >> student[j].id
                >> student[j].score[0] >> student[j].score[1]
                >> student[j].score[2] >> student[j].score[3]
                >> student[j].score[4];
        }

        double sum;
        int best_score;
        for (int j = 0; j < student_size; j++) {
            best_score = -1;
            sum = student[j].score[0] + student[j].score[1] + student[j].score[2]
                + student[j].score[3] + student[j].score[4];
            student[j].avg = sum / STUDENT;

            for (int k = 0; k < STUDENT; k++) {
                if (best_score < student[j].score[k]) {
                    best_score = student[j].score[k];
                    student[j].best_score = best_score;
                }
            }
        }

        for (int j = 0; j < student_size; j++) {
            cout << student[j].name << " " << student[j].best_score
                 << " " << fixed << setprecision(2) << student[j].avg << endl;
        }

        if (i < testcase - 1) {
            printf("\n");
        }
    }

    return 0;
}
```

---

## ⚠️ 주의 / 실수 포인트

- **`scanf` + `string` 호환 안 됨** → 반드시 `cin` 사용 (또는 `char[]`로 바꿔야 함)
- **C++로 제출해야 함** → `string`, `cout`, `iomanip` 사용 중
- `fixed << setprecision(2)` 한 번 설정하면 이후 `cout` 전체에 적용됨 → 해제하려면 `defaultfloat`
- `string`을 `printf`에 쓰려면 `.c_str()` 변환 필요: `printf("%s", name.c_str())`
- 빈 줄은 **마지막 케이스 뒤에는 출력하지 않음** → `i < testcase - 1` 조건 필수

---

## 📅 풀이 날짜

2025.04.20
