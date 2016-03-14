#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct answer {
    int numerator;
    int denominator;
} Answer;

typedef struct used_array {
    int used[10];
} Used_array;

int cmp(const void *a, const void *b)
{
    if (((Answer *)a)->numerator != ((Answer *)b)->numerator)
        return ((Answer *)a)->numerator - ((Answer *)b)->numerator;
    else
        return ((Answer *)a)->denominator - ((Answer *)b)->denominator;
}

Answer output[100000]; // 9 * 8 * 7 * 6 * 5 ot 10 * 9 * 8 * 7 * 6
int ans_index = 0;

void dfs(int num, int level, Used_array used, int target)
// no leading 0 problem because all will beused
{
    if (level == 5) {
        // check numerator to see repeat
        // printf("%d\n", num);
        int candidate = num * target;
        if (candidate > 99999 || candidate < 1000)
            return;
        if (used.used[0] == 1)
            if (candidate < 10000)
                return;
        while (candidate) {
            if (used.used[candidate % 10] == 0) {
                used.used[candidate % 10] = 1;
                candidate /= 10;
            } else {
                // printf("%d %d\n", num * target, num);
                // getchar();
                return;
            }
        }
        output[ans_index].numerator = num * target;
        output[ans_index++].denominator = num;
        return;
    } else {
        num *= 10;
        for (int i = 0; i <= 9; i++) {
            if (used.used[i] == 0) {
                used.used[i] = 1;
                num += i;
                level++;
                dfs(num, level, used, target);
                level--;
                used.used[i] = 0;
                num -= i;
            }
        }
    }
}

int first = 0;

int main()
{
    int target;
    while (scanf("%d", &target) == 1 && target) {
        if (first)
            printf("\n");
        else
            first = 1;
        ans_index = 0;
        Used_array used;
        for (int i = 0; i < 10; i++)
            used.used[i] = 0;
        memset(output, 0, sizeof(output));
        dfs(0, 0, used, target); // array is pass-by-ref

        qsort(output, ans_index, sizeof(Answer), cmp);
        if (ans_index == 0)
            printf("There are no solutions for %d.\n", target);

        for (int i = 0; i < ans_index; i++) {
            printf("%05d / %05d = %d\n", output[i].numerator, output[i].denominator,
                   target);
        }
    }

    return 0;
}