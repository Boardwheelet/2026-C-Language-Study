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
			sum += s[j]; // 각 성적 바로바로 합치기
		}
		avg = (double)sum / student; // 평균값.

		int count = 0;
		double min_s_dif = fabs(avg - s[0]); // (평균 성적 - 성적)으로 차이 비교.

		for (int j = 0; j < student; j++) {
			double s_dif = fabs(avg - s[j]); // 평균과의 차이.

			if (min_s_dif > s_dif) { // 차이가 제일 작은 수 찾기.
				min_s_dif = s_dif;
				count = j; // 평균값과 가장 근사한 값 인덱스 보관.
			}
		}

		printf("%d\n", s[count]);
	}


	return 0;
}