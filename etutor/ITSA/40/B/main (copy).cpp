#include <cstdio>
#include <cstdlib>

typedef struct data {
    double w, p;
    double r;
    int number;
} Data;

int cmp(const void *a, const void *b)
{
    return ((Data *)a)->r - ((Data *)b)->r;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        double W;
        Data input[3];
        scanf("%lf", &W);
        for (int i = 0; i < 3; i++)
            scanf("%lf", &input[i].w);
        for (int i = 0; i < 3; i++) {
            scanf("%lf", &input[i].p);
            input[i].number = i;
            input[i].r = input[i].p / input[i].w;
        }

        for (int i = 0; i < 3; i++)
            printf("%d %f, ", input[i].number, input[i].r);
        printf("\n");

        qsort(input, 3, sizeof(Data), cmp);

        double ans[4] = {0};

        for (int i = 0; i < 3; i++)
            printf("%d %f, ", input[i].number, input[i].r);
        printf("\n");

        for (int i = 0; i < 3; i++) {
            if (W - input[i].w >= 0) {
                ans[input[i].number] = input[i].w;
                ans[3] += (input[i].r * input[i].w);
            } else {
                ans[3] += (input[i].r * W);
                ans[input[i].number] = W;
                break;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (i != 3)
                printf("%.3f ", ans[i]);
            else
                printf("%.3f\n", ans[i]);
        }
    }

    return 0;
}
