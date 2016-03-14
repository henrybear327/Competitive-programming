#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <climits> //LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#define MIN(x, y) ((x) < (y) ? (x) : (y)
#define MAX(x, y) ((x) > (y) ? (x) : (y)

using namespace std;

int DP_prime[2000000] = {0};
void generate_prime()
{
    bool prime_bool[2000000] = {false};
    DP_prime[1] = 0;
    for (int i = 2; i < 2000000; i++) {
        if (prime_bool[i] == false) {
            int tmp = 2;
            while (i * tmp < 2000000) {
                prime_bool[i * tmp] = true;
                tmp++;
            }
        }
    }

    for (int i = 2; i < 2000000; i++)
        if (prime_bool[i] == false)
            DP_prime[i] = DP_prime[i - 1] + 1;
        else
            DP_prime[i] = DP_prime[i - 1];
}

int is_Palindrome[2000000] = {0};

void Palindrome()
{
    is_Palindrome[1] = 1;

    for (int i = 1; i < 2000000; i++) {
        int len = 0, num = i;
        while (num) {
            len++;
            num /= 10;
        }

        if (len % 2 == 1) {
            int mid_len = (len - 1) / 2;
            if (mid_len == 0)
                is_Palindrome[i] = is_Palindrome[i - 1] + 1;
            else {
                int array[len], tmp = i, j = 1;
                while (tmp) {
                    array[len - j++] = tmp % 10;
                    tmp /= 10;
                }

                j = 1;
                while (mid_len--) {
                    if (array[j - 1] != array[len - j])
                        break;
                    j++;
                }
                if (mid_len == -1)
                    is_Palindrome[i] = is_Palindrome[i - 1] + 1;
                else
                    is_Palindrome[i] = is_Palindrome[i - 1];
            }
        } else {
            int mid_len = len / 2;
            int array[len], tmp = i, j = 1;
            while (tmp) {
                array[len - j++] = tmp % 10;
                tmp /= 10;
            }

            j = 1;
            while (mid_len--) {
                if (array[j - 1] != array[len - j])
                    break;
                j++;
            }
            if (mid_len == -1)
                is_Palindrome[i] = is_Palindrome[i - 1] + 1;
            else
                is_Palindrome[i] = is_Palindrome[i - 1];
        }
    }
}

int main()
{

    int p, q;

    generate_prime();
    Palindrome();

    scanf("%d %d", &p, &q);
    int max = -1;
    for (int i = 1; i < 2000000; i++) {
        if (q * DP_prime[i] <= p * is_Palindrome[i]) {
            //printf("%d\n", i);
            max = i;
        }
    }

    if (max != -1)
        printf("%d\n", max);
    else
        printf("Palindromic tree is better than splay tree\n");

    return 0;
}
