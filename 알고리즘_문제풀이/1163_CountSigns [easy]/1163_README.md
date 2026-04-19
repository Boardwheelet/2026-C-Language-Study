# 1163번 - 음수 양수 갯수 세기

## 📋 문제 정보

- **사이트** : ASCODE
- **분류** : 반복문
- **제한** : 시간 1초 / 메모리 128MB
- **링크** : http://ascode.org/problem.php?id=1163

---

## 📝 문제 설명

n개의 정수가 주어질 때, **음수와 양수의 개수**를 각각 출력한다. (0은 카운트 제외)

---

## 📥 입력

```
첫 줄: 테스트케이스 수 T (1 ≤ T ≤ 10)
다음 T묶음: 정수 개수 n → n개의 정수 (-1000 이상 1000 이하)
```

## 📤 출력

```
음수 개수, 양수 개수 순으로 한 줄 출력
```

---

## 💡 예제

**입력**
```
2
3
-1 3 2
5
98 0 -345 987 -21
```

**출력**
```
1 2
2 2
```

---

## 🧠 풀이 핵심

- `input > 0` → 양수 카운트
- `input < 0` → 음수 카운트
- `input == 0` → **무시** (조건 없음)
- 출력 순서: **음수 먼저, 양수 나중**

---

## ✅ 내 코드

```c
#include <stdio.h>

int main() {
    int testcase;
    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        int sign = 0, unsign = 0;  // sign=음수, unsign=양수

        int n;
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            int input;
            scanf("%d", &input);

            if (input > 0) unsign++;
            else if (input < 0) sign++;
        }

        printf("%d %d\n", sign, unsign);  // 음수 양수 순
    }

    return 0;
}
```

---

## ⚠️ 주의 / 실수 포인트

- 출력 순서 **음수 → 양수** 주의 (반대로 출력하면 틀림)
- **0은 음수도 양수도 아님** → `else if` 없이 그냥 넘어가면 됨

---

## 📅 풀이 날짜

2026.04.19
