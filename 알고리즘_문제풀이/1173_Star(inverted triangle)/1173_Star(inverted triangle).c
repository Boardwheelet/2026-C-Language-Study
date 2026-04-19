#include <stdio.h>

int main() {
	int test_case;
	scanf("%d", &test_case);

	for (int i = 0; i < test_case; i++) {
		int size;
		scanf("%d", &size);

		int alph = 0;
		for (int j = size; j > 0; j--) { // 가로 길이 갯수
			for (int k = 0; k < j; k++) {
				printf("%c", 65 + alph);
			}

			alph++;
			printf("\n");
		}
		printf("\n");
	}


	return 0;
}