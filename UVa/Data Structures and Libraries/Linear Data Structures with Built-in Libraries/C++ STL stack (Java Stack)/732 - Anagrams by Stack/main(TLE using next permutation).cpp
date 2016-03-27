#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

char input[100];
char input2[100];
char io_list[210];
int len;

void check()
{
    stack<int> tmp;
    int idx = 0, r_idx = 0;
    bool bad = false;
    for (int i = 0; i < len * 2; i++) {
        if (io_list[i] == 'i')
            tmp.push(input[idx++]);
        else {
            if (tmp.empty()) {
                bad = true;
                break;
            } else {
                if (tmp.top() == input2[r_idx++])
                    tmp.pop();
                else {
                    bad = true;
                    break;
                }
            }
        }
    }

    if (bad == false) {
        printf("%c", io_list[0]);
        for (int i = 1; i < len * 2; i++)
            printf(" %c", io_list[i]);
        printf("\n");
    }
}

int main()
{
    while (fgets(input, 100, stdin) != NULL &&
           fgets(input2, 100, stdin) != NULL) {
        printf("[\n");

        len = strlen(input) - 1;

        if (len != (int)strlen(input2) - 1) {
            printf("]\n");
            continue;
        }

        for (int i = 0; i < len * 2; i++)
            io_list[i] = i < len ? 'i' : 'o';

        check();
        while (next_permutation(io_list + 1, io_list + len * 2 - 1)) {
            check();
        }

        printf("]\n");
    }

    return 0;
}
