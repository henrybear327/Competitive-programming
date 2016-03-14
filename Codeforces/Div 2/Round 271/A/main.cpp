#include <bits/stdc++.h>
// LLONG_MIN LLONG_MAX INT_MIN INT_MAX

using namespace std;

// warnings when const is not added
const char *kb[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
char convert(char c, char dir)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (c == kb[i][j]) {
                if (dir == 'R')
                    return kb[i][j - 1];
                else
                    return kb[i][j + 1];
            }
        }
    }
    return '0';
}

int main()
{
    char inp[1000];
    fgets(inp, 1000, stdin);

    char c;
    sscanf(inp, "%c", &c);

    fgets(inp, 1000, stdin);
    int len = strlen(inp);
    for (int i = 0; i < len - 1; i++) {
        printf("%c", convert(inp[i], c));
    }

    return 0;
}
