#include <cstdio>
#include <cstdlib>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main()
{
    int cases;
    scanf("%d", &cases);
    getchar();

    int ones = 0, zeros = 0;
    for (int i = 0; i < cases; i++) {
        char temp;
        scanf("%c", &temp);
        if (temp - '0' == 0)
            zeros++;
        else
            ones++;
    }

    //    printf("%d %d", zeros, ones);

    cases = (cases - 2 * MIN(zeros, ones));
    printf("%d", cases);

    return 0;
}
