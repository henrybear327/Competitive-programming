#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

typedef struct fraction {
    long long int numerator;
    long long int denominator;
} Fraction;

int main()
{
    int test_case;
    while (scanf("%d", &test_case) == 1) {
        getchar();
        while (test_case--) {
            char input[100];
            fgets(input, 100, stdin);

            int len = strlen(input) - 1;
            Fraction L, C, R;
            L.numerator = 0;
            L.denominator = 1;
            C.numerator = 1;
            C.denominator = 1;
            R.numerator = 1;
            R.denominator = 0;
            for (int i = 0; i < len; i++) {
                if (input[i] == 'L') {
                    R.numerator = C.numerator;
                    R.denominator = C.denominator;
                    C.numerator = L.numerator + C.numerator;
                    C.denominator = L.denominator + C.denominator;
                } else if (input[i] == 'R') {
                    L.numerator = C.numerator;
                    L.denominator = C.denominator;
                    C.numerator = R.numerator + C.numerator;
                    C.denominator = R.denominator + C.denominator;
                }
            }
            printf("%lld/%lld\n", C.numerator, C.denominator);
        }
    }

    return 0;
}
