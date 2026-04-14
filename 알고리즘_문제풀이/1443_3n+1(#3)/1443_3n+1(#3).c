#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    for (int i = 0; i < testcase; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        // a랑 b값 정렬시키기
        if (a > b) {
            int tmp = b;
            b = a;
            a = tmp;
        }

        int best_m = 0; // 제일 길었던 수열의 길이
        int best_n = 0; // 제일 컸던 값

        // a랑 b '사이'에 있는 정수 하나하나씩 수열 찾기
        for (int j = a; j <= b; j++) {

            int n = j; // 수열의 각 '항'
            int m = 1; // 수열의 길이 (마지막 1도 포함시켜야하므로 1로 초기화)

            while (n != 1) {
                if (n % 2 == 1) { // n이 홀수라면
                    n = (3 * n) + 1;
                }
                else { // n이 짝수라면
                    n = n / 2;
                }
                m++;
            }

            if (m > best_m) { // 제일 큰 m이 나온다면
                best_m = m;
                best_n = j; // 가장 큰 길이를 지닌 n 찾기
            }
        }

        printf("%d %d\n", best_n, best_m);

    }


    return 0;
}
