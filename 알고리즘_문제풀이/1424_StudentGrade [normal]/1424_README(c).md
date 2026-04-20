# 1424번 - 학생 성적 관리 시스템 (순수 C 버전)

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

- **`string` 대신 `char name[21]`** → 순수 C에서 `scanf("%s", ...)`와 완벽 호환
- 평균: `int sum / 5.0f` → float 리터럴 붙여야 소수점 제대로 계산됨
- 최고 점수: `best = -1`로 초기화 후 5과목 순회
- 소수점 출력: `printf("%.2f", avg)`
- 빈 줄: `if (i < T - 1) printf("\n")`

```c
// 핵심 스니펫
student[j].avg = sum / 5.0f;   // 5.0f 안 붙이면 정수 나눗셈됨!

int best = -1;
for (int k = 0; k < SUBJECTS; k++)
    if (student[j].score[k] > best)
        best = student[j].score[k];

printf("%s %d %.2f\n", student[j].name, student[j].best_score, student[j].avg);
```

---

## ✅ 내 코드

```c
#pragma warning(disable:4996)
#include <stdio.h>

#define SUBJECTS 5

struct Student {
    char name[21];
    int id;
    int score[SUBJECTS];
    int best_score;
    float avg;
};

int main() {
    struct Student student[50];
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        for (int j = 0; j < N; j++) {
            scanf("%s %d %d %d %d %d %d",
                student[j].name, &student[j].id,
                &student[j].score[0], &student[j].score[1],
                &student[j].score[2], &student[j].score[3],
                &student[j].score[4]);

            int sum = 0;
            for (int k = 0; k < SUBJECTS; k++)
                sum += student[j].score[k];
            student[j].avg = sum / 5.0f;

            int best = -1;
            for (int k = 0; k < SUBJECTS; k++)
                if (student[j].score[k] > best)
                    best = student[j].score[k];
            student[j].best_score = best;
        }

        for (int j = 0; j < N; j++)
            printf("%s %d %.2f\n", student[j].name, student[j].best_score, student[j].avg);

        if (i < T - 1)
            printf("\n");
    }

    return 0;
}
```

---

## ⚠️ 주의 / 실수 포인트

- **`string` + `scanf` 호환 안 됨** → C 버전은 반드시 `char name[N]` 사용
- **`scanf("%s", name)`** → 배열명은 이미 포인터이므로 `&` 붙이면 안 됨 (`&name` ❌)
- **`sum / 5`** → 정수 나눗셈이라 소수점 버려짐 → 반드시 **`5.0f`** 붙일 것
- **`#pragma warning(disable:4996)`** → MSVC(Visual Studio)에서 `scanf` 보안 경고 억제용, 제출 시엔 없어도 됨
- **C로 제출** / C++ 버전(`string`, `cout`)과 혼용 금지
- 빈 줄은 마지막 케이스 뒤엔 없음 → `i < T - 1` 조건 필수

---

## 🔄 C vs C++ 버전 비교

| 항목 | C 버전 | C++ 버전 |
|------|--------|----------|
| 문자열 | `char name[21]` | `string name` |
| 입력 | `scanf("%s", name)` | `cin >> name` |
| 소수점 출력 | `printf("%.2f", avg)` | `cout << fixed << setprecision(2)` |
| 제출 언어 | C | C++ |
| float 타입 | `float avg` | `double avg` |

---

## 📅 풀이 날짜

2025.04.20
