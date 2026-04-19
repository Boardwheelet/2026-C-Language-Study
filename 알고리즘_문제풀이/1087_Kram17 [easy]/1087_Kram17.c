#include <stdio.h>

int main() {
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		int price;
		scanf("%d", &price);

		int sum = 0;
		int count = 0;
		for (int j = 1; sum < price; j++) {
			if (j % 7 == 5 || j % 7 == 6 || j % 7 == 0) { // 주말이벤트
				sum += 60000;
			}
			else { // 월 ~ 목요일
				sum += 36000;
			}
			count++;
		}

		printf("%d\n", count);
	}


	return 0;
}