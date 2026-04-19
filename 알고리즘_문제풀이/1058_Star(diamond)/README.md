# 1058번 - 별 찍기 - 마름모

## 📋 문제 정보

- **사이트** : ASCODE
- **분류** : 반복문 / 별찍기
- **제한** : 시간 1초 / 메모리 128MB
- **링크** : http://ascode.org/problem.php?id=1058

---

## 📝 문제 설명

크기 n의 마름모를 출력한다.

---

## 📥 입력

```
첫 줄: 테스트케이스 수 t (0 < t < 10)
다음 t줄: 마름모 크기 n
```

## 📤 출력

```
마름모를 출력
```

---

## 💡 예제

**입력**
```
3
4
5
2
```

**출력**
```
   *
  ***
 *****
*******
 *****
  ***
   *
```

---

## 🧠 풀이 핵심

마름모 = **위쪽 삼각형** + **아래쪽 역삼각형**

| 구분 | 줄(j) 범위 | 앞 공백 | 별 개수 |
|------|-----------|---------|---------|
| 위 삼각형 | `j = 1 ~ starSize` | `starSize - j` | `j*2 - 1` |
| 아래 역삼각형 | `j = starSize-1 ~ 1` | `starSize - j` | `j*2 - 1` |

> 핵심: **공백 수식이 위아래 동일 → `starSize - j`** 하나로 통일  
> 역삼각형을 `j = starSize-1`부터 시작해서 가운데 줄 중복을 방지

---

## ✅ 내 코드

```c
#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    // 먼저 삼각형을 출력하고 이후 역삼각형을 출력하는 식으로 해보자.

    for (int i = 0; i < testcase; i++) {
        int starSize;
        scanf("%d", &starSize);

        // 삼각형 출력
        for (int j = 1; j <= starSize; j++){ //가로줄 개수
            // 공백 출력 (핵심: 뒤쪽 공백 신경 X 앞쪽만 공백 찍으면 됨)
            for (int k = 0; k < starSize - j; k++) {
                printf(" ");
            }
            // 별 출력
            for (int k = 0; k < (j * 2) - 1; k++) {
                printf("*");
            }
            printf("\n");
        }

        // 역삼각형 출력
        for (int j = starSize - 1; j > 0 ; j--) { //가로줄 개수
            // 공백 출력
            for (int k = 0; k < starSize - j; k++) {
                printf(" ");
            }
            // 별 출력
            for (int k = 0; k < (j * 2) - 1; k++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
```

---

## ⚠️ 주의 / 실수 포인트

- 역삼각형 시작을 `j = starSize`가 아닌 **`j = starSize-1`** 부터 → 가운데 줄 중복 방지
- `starSize`를 직접 변형(`starSize -= 1`)하면 공백 수식이 `(starSize-j)+1`처럼 꼬임 → **원본 유지가 핵심**

---

## 📅 풀이 날짜

2026.04.19
