# 1165번 - 평범한 학생 찾기

## 📋 문제 정보

- **사이트** : ASCODE
- **분류** : 배열, 반복문, 실수 연산
- **제한** : 시간 1초 / 메모리 128MB
- **링크** : http://ascode.org/problem.php?id=1165

---

## 📝 문제 설명

N명의 점수 중, 점수들의 **평균값에 가장 근접한 점수**를 찾아 출력한다.  
평균은 실수(소수점)임에 주의.

---

## 📥 입력

```
T (테스트 케이스 수, 1 <= T <= 10)
N (학생 수, 3 <= N <= 20)
S[0] S[1] ... S[N-1]  (각 점수, 0 <= S[i] <= 1000)
```

## 📤 출력

```
각 테스트 케이스마다 평균에 가장 근접한 점수 출력
```

---

## 💡 예제

| 입력 | 출력 |
|------|------|
| 2<br>5<br>90 20 30 10 70<br>6<br>100 82 49 57 0 95 | 30<br>57 |

**예제 1 추적:**
- 평균: 220 / 5 = **44.0**
- 차이: \|44-90\|=46, \|44-20\|=24, \|44-30\|=**14**, \|44-10\|=34, \|44-70\|=26
- 최솟값 → **30** ✅

**예제 2 추적:**
- 평균: 383 / 6 = **63.83...**
- \|63.83-57\| = 6.83 이 가장 작음 → **57** ✅

---

## 🧠 풀이 핵심

1. 점수 입력받으면서 `sum` 누적
2. **`(double)sum / N`** 으로 실수 평균 계산 ← 핵심 주의 포인트
3. 모든 점수에 대해 `fabs(avg - s[j])` 계산
4. 최솟값 갱신 시 인덱스 저장 → 마지막에 `s[count]` 출력

```c
// 핵심 로직
avg = (double)sum / student;  // 반드시 실수 나눗셈

double min_dif = fabs(avg - s[0]);
int count = 0;
for (int j = 0; j < student; j++) {
    double dif = fabs(avg - s[j]);
    if (min_dif > dif) {
        min_dif = dif;
        count = j;
    }
}
```

---

## ✅ 내 코드

**원본 (오류 있음):**
```c
avg = sum / student;  // ❌ 정수 나눗셈 → 소수점 버림 발생
```

**수정본:**
```c
#include <stdio.h>
#include <math.h>

int main() {
    int testcase;
    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        int s[1000] = { 0 };
        int sum = 0;
        double avg = 0;

        int student;
        scanf("%d", &student);

        for (int j = 0; j < student; j++) {
            scanf("%d", &s[j]);
            sum += s[j];
        }
        avg = (double)sum / student;  // ✅ 실수 나눗셈으로 수정

        int count = 0;
        double min_s_dif = fabs(avg - s[0]);

        for (int j = 0; j < student; j++) {
            double s_dif = fabs(avg - s[j]);
            if (min_s_dif > s_dif) {
                min_s_dif = s_dif;
                count = j;
            }
        }

        printf("%d\n", s[count]);
    }

    return 0;
}
```

---

## ⚠️ 주의 / 실수 포인트

- **`sum / student`는 정수 나눗셈** → 소수점이 잘린 평균으로 계산됨
  - 문제에서 "평균값은 실수값"이라고 명시했으므로 반드시 `(double)sum / student` 사용
  - 예제는 우연히 통과되더라도 채점 케이스에서 틀릴 수 있음
- `fabs()` 사용 시 `#include <math.h>` 필수 (컴파일 시 `-lm` 옵션 필요할 수 있음)
- `min_s_dif` 초기값을 `s[0]`과의 차이로 설정하고, 루프를 `j=0`부터 시작해도 문제없음 (첫 번째는 갱신 안 될 뿐)

---

## 📅 풀이 날짜

2026.04.19
