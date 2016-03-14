#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

#ifdef _WIN32
#define lld "I64d"
#else
#define lld "lld"
#endif

using namespace std;

int main()
{
    int n, m;
    char input[200100];
    fgets(input, 200100, stdin);
    sscanf(input, "%d %d", &n, &m);

    int letter[26];
    for (int i = 0; i < 26; i++) {
        letter[i] = i;
    }

    vector<int> loc[26];
    fgets(input, 200100, stdin);
    for (int i = 0; i < n; i++) {
        loc[input[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < m; i++) {
        fgets(input, 200100, stdin);
        if (input[0] == input[2])
            continue;

        int v1 = input[0] - 'a', v2 = input[2] - 'a';

        for (int j = 0; j < 26; j++) {
            if (letter[j] == v1) {
                v1 = j;
                break;
            }
        }

        for (int j = 0; j < 26; j++) {
            if (letter[j] == v2) {
                v2 = j;
                break;
            }
        }

        letter[v1] = input[2] - 'a';
        letter[v2] = input[0] - 'a';
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < (int)loc[i].size(); j++) {
            input[loc[i][j]] = letter[i] + 'a';
        }
    }
    input[n] = '\0';

    printf("%s\n", input);

    return 0;
}
