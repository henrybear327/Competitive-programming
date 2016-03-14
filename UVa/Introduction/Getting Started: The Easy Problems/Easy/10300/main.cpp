#include <cstdio>

int main()
{
    int cases;
    while (scanf("%d", &cases) != EOF) {
        while (cases--) {
            int farmer;
            scanf("%d", &farmer);
            int answer = 0;
            while (farmer--) {
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);

                answer += (a * c);
            }

            printf("%d\n", answer);
        }
    }

    return 0;
}
