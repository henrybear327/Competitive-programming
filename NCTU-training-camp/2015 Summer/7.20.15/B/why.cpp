#include <cstdio>
#include <cstring>
using namespace std;

char T[1000010], P[10010]; // T = text, P = pattern
int b[10010], n, m, count; // b = back table, n = length of T, m = length of P

void kmpPreprocess() // call this before calling kmpSearch()
{
    int j = 0; // starting values
    b[0] = 0;
    for (int i = 1; i < m;) {
        if (P[i] == P[j]) {
            b[i] = j + 1; // here
            i++;
            j++;
        } else {
            if (j > 0) {
                j = b[j - 1];
            } else {
                b[i] = 0;
                i++;
            }
        }
    }

    // for (int i = 0; i < m; i++)
    // printf("%d ", b[i]);
    // printf("\n");
} // in the example of P = "SEVENTY SEVEN" above

void kmpSearch() // this is similar as kmpPreprocess(), but on string T
{
    int i = 0;
    for (int j = 0; j < n;) {
        if (P[i] == T[j]) {
            // printf("same at i %d j %d t[%d] = %c\n", i, j, j, T[j]);
            if (i != m - 1) {
                i++;
                j++;
            } else {
                // printf("Found at %d\n", j - m + 1);
                count++;
                i = b[i - 1];
            }
        } else {
            // printf("mismatch\n");
            if (i > 0) {
                i = b[i - 1];
                // printf("reset i %d j %d\n", i, j);
            } else {
                j++;
            }
            // printf("i %d j %d\n", i, j);
        }
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    fgets(P, 10010, stdin);
    while (test--) {
        count = 0;

        memset(b, 0, sizeof(b));

        fgets(P, 10010, stdin);
        // printf("%s", P);
        fgets(T, 1000010, stdin);
        // printf("%s", T);
        n = (int)strlen(T) - 1;
        m = (int)strlen(P) - 1;

        kmpPreprocess();
        kmpSearch();

        printf("%d\n", count);
    }

    return 0;
}