#pragma warning(disable:4996)
#include <stdio.h>

#define SUBJECTS 5

struct Student {
    char name[21];
    int id;
    int score[SUBJECTS];
    int best_score;
    float avg;
};

int main() {
    struct Student student[50];
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        for (int j = 0; j < N; j++) {
            scanf("%s %d %d %d %d %d %d",
                student[j].name, &student[j].id,
                &student[j].score[0], &student[j].score[1],
                &student[j].score[2], &student[j].score[3],
                &student[j].score[4]);

            // 평균
            int sum = 0;
            for (int k = 0; k < SUBJECTS; k++)
                sum += student[j].score[k];
            student[j].avg = sum / 5.0f;

            // 최고점수
            int best = -1;
            for (int k = 0; k < SUBJECTS; k++)
                if (student[j].score[k] > best)
                    best = student[j].score[k];
            student[j].best_score = best;
        }

        for (int j = 0; j < N; j++)
            printf("%s %d %.2f\n", student[j].name, student[j].best_score, student[j].avg);

        if (i < T - 1)
            printf("\n");
    }

    return 0;
}