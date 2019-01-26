#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    char inp[222];
    scanf("%s", inp);

    int k;
    scanf("%d", &k);

    int star = 0, question = 0;
    int len = strlen(inp);
    for (int i = 0; i < len; i++) {
        if (inp[i] == '*')
            star++;
        if (inp[i] == '?')
            question++;
    }
    if (len - 2 * (star + question) > k) { // min length > k
        printf("Impossible\n");
        return 0;
    }

    if (star == 0 && len - question < k) { // max length < k
        printf("Impossible\n");
        return 0;
    }

    if (k < len - (question + star)) {
        int rm = len - (question + star) - k;
        for (int i = 0; i < len; i++) {
            if (inp[i] == '*' || inp[i] == '?')
                continue;
            if (i + 1 < len && (inp[i + 1] == '?' || inp[i + 1] == '*')) {
                if (rm > 0) {
                    rm--;
                    continue;
                }
                printf("%c", inp[i]);
            } else {
                printf("%c", inp[i]);
            }
        }
    } else {
        int diff = k - (len - (question + star));
        for (int i = 0; i < len; i++) {
            if (inp[i] == '*' || inp[i] == '?')
                continue;
            printf("%c", inp[i]);
            if (i + 1 < len) {
                while (inp[i + 1] == '*' && diff > 0) {
                    printf("%c", inp[i]);
                    diff--;
                }
                continue;
            }
        }
    }

    return 0;
}
