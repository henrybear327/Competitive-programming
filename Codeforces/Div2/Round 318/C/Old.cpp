#include <cstdio>

long long int gcd(long long int a, long long int b)
{
    if (a > b) {
        long long int tmp = a;
        a = b;
        b = tmp;
    }

    return a == 0 ? b : gcd(b % a, a);
}

long long int gcd2(long long int a, long long int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

long long int lcm(long long int a, long long int b)
{
    printf("%lld %lld, %lld %lld\n", a, b, gcd(a, b), gcd2(a, b));
    return a / gcd2(a, b) * b;
}

int main()
{
    int total;
    scanf("%d", &total);

    long long int inp[total];
    for (int i = 0; i < total; i++)
        scanf("%lld", &inp[i]);

    long long int lcm_ans = 0;
    for (int i = 1; i < total; i++) {
        printf("i %d, %lld %lld\n", i, inp[i - 1], inp[i]);
        printf("before %lld\n", lcm_ans);
        if (i == 1)
            lcm_ans = lcm(inp[i - 1], inp[i]);
        else
            lcm_ans = lcm(lcm_ans, inp[i]);
        printf("after %lld\n", lcm_ans);
    }

    for (int i = 0; i < total; i++)
        inp[i] = lcm_ans / inp[i];

    bool flag = true;
    for (int i = 0; i < total; i++) {
        while (inp[i] % 2 == 0)
            inp[i] /= 2;
        while (inp[i] % 3 == 0)
            inp[i] /= 3;

        if (inp[i] != 1) {
            flag = false;
            break;
        }
    }

    printf("%s\n", flag == true ? "Yes" : "No");

    return 0;
}
