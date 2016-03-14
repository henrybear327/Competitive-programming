#include <bits/stdc++.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y)) o

int main()
{
    char input[300100] = {'\0'};

    int len, queries;
    scanf("%d %d", &len, &queries);
    fgets(input, 300100, stdin);
    fgets(input, 300100, stdin);

    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (input[i] == '.') {
            int consecutive = 1;
            while (input[++i] == '.')
                consecutive++;
            ans += (consecutive - 1);
        }
    }

    for (int i = 0; i < queries; i++) {
        int pos;
        char letter;
        scanf("%d %c", &pos, &letter);

        pos--;
        int look_left = pos > 0 && input[pos - 1] == '.';
        int look_right = pos < len - 1 && input[pos + 1] == '.';

        if (letter == '.' && input[pos] != '.') {
            ans += (look_left + look_right);
            printf("%d\n", ans);
        } else if (input[pos] == '.' && letter != '.') {
            ans -= (look_left + look_right);
            printf("%d\n", ans);
        } else {
            printf("%d\n", ans);
        }

        input[pos] = letter;
    }

    return 0;
}
