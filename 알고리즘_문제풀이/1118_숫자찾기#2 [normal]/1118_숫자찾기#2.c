// #define _CRT_SECURE_NO_WARNINGS : 혹시나 필요할 수 있으니.
#include <stdio.h>
#include <algorithm>

int arrM[1500000];
int arrN[10000];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    /* 입력받기 */
    for (int i = 0; i < m; i++) scanf("%d", &arrM[i]);
    for (int i = 0; i < n; i++) scanf("%d", &arrN[i]);

    /* 정렬 */
    std::sort(arrM, arrM + m); // sort(시작포인터, 끝포인터) → arrM[0] ~ arrM[m-1] 정렬

    /* 이진탐색:
    * 배열의 중간 값(mid)을 고른다.
    * 찾는 값과 mid를 비교한다.
    * 같으면 → 탐색 성공!
    * 찾는 값이 더 크면 → mid보다 오른쪽 절반만 탐색
    * 찾는 값이 더 작으면 → mid보다 왼쪽 절반만 탐색
    * 범위가 없어질 때까지 반복
    */
    int count = 0;

    for (int j = 0; j < n; j++) { // 찾으려는 개수
        int left = 0;
        int right = m - 1; // 인덱스의 위치니까.

        while (true) {
            if (arrM[(left + right) / 2] > arrN[j]) { // arr[M]의 중간값이 N보다 크면
                right = ((left + right) / 2) - 1;
            }
            else if (arrM[(left + right) / 2] < arrN[j]) { // arr[M]의 중간값이 N보다 크면
                left = ((left + right) / 2) + 1;
            }
            else { // 값이 같으면..
                count++; // 찾았다!
                break;
            }

            // arrN[]의 원소가 arr[M] 배열안에 없다면?
            if (right < left) {
                break;
            }
        }
    }


    printf("%d", count);
    return 0;
}