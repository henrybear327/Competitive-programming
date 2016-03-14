#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) && (a || b)) {
        int ans = 0, carry = 0;
        while (a && b) {
            if (carry + a % 10 + b % 10 > 9) {
                ans++;
                carry = 1;
            } else {
                carry = 0;
            }
            a /= 10;
            b /= 10;
        }

        while (a) {
            if (carry + a % 10 > 9) {
                carry = 1;
                ans++;
            } else
                carry = 0;
            a /= 10;
        }

        while (b) {
            if (carry + b % 10 > 9) {
                carry = 1;
                ans++;
            } else
                carry = 0;
            b /= 10;
        }

        if (ans == 0)
            printf("No carry operation.\n");
        else
            printf("%d carry %s.\n", ans, ans == 1 ? "operation" : "operations");
    }

    return 0;
}
