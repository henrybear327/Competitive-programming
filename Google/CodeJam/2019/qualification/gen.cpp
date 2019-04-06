#include <bits/stdc++.h>

using namespace std;

vector<int> prime;
void genPrime()
{
    prime.push_back(2);
    for (int i = 3; i < 400; i += 2) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0)
                goto fail;
        }

        prime.push_back(i);
fail:
        continue;
    }
}

int main()
{
    genPrime();
    srand(time(NULL));
    printf("1\n");
    int len = 50;
    printf("400 %d\n", len - 1);
    int inp[len];
    int p[26];
    random_shuffle(prime.begin(), prime.end());
    for (int i = 0; i < 26; i++)
        p[i] = prime[i];
    sort(p, p + 26);
    for (int i = 0; i < 26; i++)
        inp[i] = i;
    for (int i = 26; i < len; i++) {
        inp[i] = rand() % 26;
    }
    random_shuffle(inp, inp + len);
	fprintf(stderr, "Case #1: ");
    for (int i = 0; i < len; i++)
        fprintf(stderr, "%c", inp[i] + 'A');
    fprintf(stderr, "\n");

    for (int i = 1; i < len; i++) {
        printf("%d ", p[inp[i]] * p[inp[i - 1]]);
    }

    return 0;
}
