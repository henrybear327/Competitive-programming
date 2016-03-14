#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

bool is_not_prime[1000010];
vector<int> prime;
void make_prime()
{
    memset(is_not_prime, false, sizeof(is_not_prime));

    for (int i = 2; i <= 1000009; i++) {
        if (is_not_prime[i] == false) {
            prime.push_back(i);
            for (int j = i * 2; j <= 1000009; j += i) {
                is_not_prime[j] = true;
            }
        }
    }
}

int main()
{
    make_prime();
    long long int n;
    scanf("%lld", &n);

    long long int ans = 1, n_tmp = n;
    for (int i = 0; i < (int)prime.size() && prime[i] * prime[i] <= n; i++) {
        if (n_tmp % prime[i] == 0) {
            ans *= prime[i];
            while (n_tmp % prime[i] == 0)
                n_tmp /= prime[i];
        }
    }

    printf("%lld\n", ans * n_tmp);

    return 0;
}
