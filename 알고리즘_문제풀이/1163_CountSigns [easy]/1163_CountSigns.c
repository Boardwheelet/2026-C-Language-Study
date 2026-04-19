#include <stdio.h>

int main() {
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		int sign = 0, unsign = 0; // 음수, 양수

		int n;
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			int input;
			scanf("%d", &input);

			if (input > 0) { unsign++; }
			else if (input < 0) { sign++; }
		}

		printf("%d %d\n", sign, unsign);
	}


	return 0;
}