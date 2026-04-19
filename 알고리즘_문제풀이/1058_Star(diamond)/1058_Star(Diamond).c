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
        for (int j = 1; j <= starSize; j++) { //가로줄 개수
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
        for (int j = starSize - 1; j > 0; j--) { //가로줄 개수
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
