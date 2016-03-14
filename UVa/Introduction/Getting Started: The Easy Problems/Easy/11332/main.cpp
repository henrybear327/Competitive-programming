#include <cstdio>

int f(int num)
{
    int ans = 0;
    while (num) {
        ans += num % 10;
        num /= 10;
    }

    return ans;
}
int main()
{
    int number, prev = -1;
    while (scanf("%d", &number), number != 0) {
        while (1) {
            number = f(number);
            if (prev == number) {
                printf("%d\n", number);
                prev = -1;
                break;
            } else
                prev = number;
        }
    }

    return 0;
}
