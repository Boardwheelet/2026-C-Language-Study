# 1118번 - 숫자 찾기 #2

## 📋 문제 정보

- **사이트** : ASCODE
- **분류** : 1차원배열, 탐색
- **제한** : 시간 1초 / 메모리 128MB
- **링크** : http://ascode.org/problem.php?id=1118

---

## 📝 문제 설명

m개의 정수 배열이 주어지고, n개의 정수가 주어질 때 → n개 중 몇 개가 m개의 배열 안에 존재하는지 개수를 출력.

---

## 📥 입력

```
첫 줄: m n
둘째 줄: m개의 정수
셋째 줄: n개의 정수
(1 <= m <= 1,500,000 / 1 <= n <= 10,000)
```

## 📤 출력

```
n개 중 m배열에 포함된 정수의 개수 출력
```

---

## 💡 예제

| 입력 | 출력 |
|------|------|
| 10 3<br>1 2 3 4 5 6 7 8 9 0<br>3 11 5 | 2 |

- 3 → arrM에 있음 ✅
- 11 → arrM에 없음 ❌
- 5 → arrM에 있음 ✅

---

## 🧠 풀이 핵심

### 전략: 정렬 + 이진 탐색 (Binary Search)

m이 최대 150만 → 선형 탐색(O(m×n))은 너무 느림 → **이진 탐색(O(n log m)** 사용

**이진 탐색 흐름:**
```
left=0, right=m-1
mid = (left+right)/2

arrM[mid] > target  →  right = mid - 1  (왼쪽 절반으로)
arrM[mid] < target  →  left  = mid + 1  (오른쪽 절반으로)
arrM[mid] == target →  count++, break   (찾음!)
right < left        →  break            (없음!)
```

**핵심 코드 스니펫:**
```c
std::sort(arrM, arrM + m);

for (int j = 0; j < n; j++) {
    int left = 0, right = m - 1;
    while (true) {
        int mid = (left + right) / 2;
        if      (arrM[mid] > arrN[j]) right = mid - 1;
        else if (arrM[mid] < arrN[j]) left  = mid + 1;
        else { count++; break; }
        if (right < left) break;
    }
}
```

---

## ✅ 내 코드

```c
// #define _CRT_SECURE_NO_WARNINGS : 혹시나 필요할 수 있으니.
#include <stdio.h>
#include <algorithm>

int arrM[1500000];
int arrN[10000];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) scanf("%d", &arrM[i]);
    for (int i = 0; i < n; i++) scanf("%d", &arrN[i]);

    std::sort(arrM, arrM + m);

    int count = 0;

    for (int j = 0; j < n; j++) {
        int left = 0;
        int right = m - 1;

        while (true) {
            if (arrM[(left + right) / 2] > arrN[j]) {
                right = ((left + right) / 2) - 1;
            }
            else if (arrM[(left + right) / 2] < arrN[j]) {
                left = ((left + right) / 2) + 1;
            }
            else {
                count++;
                break;
            }

            if (right < left) {
                break;
            }
        }
    }

    printf("%d", count);
    return 0;
}
```

---

## ⚠️ 주의 / 실수 포인트

- **right 초기값은 `m - 1`**: 인덱스 기준이므로 m이 아님
- **탈출 조건 순서 주의**: `right < left` 체크를 while 조건보다 반드시 루프 **하단**에서 해야 함 (mid 접근 이전에 범위 확인 안 하면 잘못된 인덱스 접근 가능)
  - 이 코드는 `while(true)` + 하단 break로 올바르게 처리함 ✅
- **오버플로우 참고**: `(left + right) / 2`는 인덱스 합이 최대 ~300만 수준이라 이 문제에선 안전. 일반적으로는 `left + (right - left) / 2`가 더 안전한 관용구
- **정렬 먼저!**: 이진 탐색은 반드시 정렬된 배열에서만 동작함. sort 빠뜨리면 완전히 틀린 결과

---

## 📅 풀이 날짜

2025.04.20
