#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<char, int> ii;

int run(int res, ii inp)
{
    if (inp.first == '|')
        return res | inp.second;
    else if (inp.first == '&')
        return res & inp.second;
    else
        return res ^ inp.second;
}

void get(int bit[], int num)
{
    for (int i = 0; i < 10; i++) {
        if ((num >> i) & 1) {
            bit[i] = 1;
        } else {
            bit[i] = 0;
        }
    }
}

#define ALWAYS_ON 1
#define ALWAYS_OFF 0
#define ALWAYS_FLIP 2
#define NONE -1

ii ans_cmd[3];
void print(int index, char c, int status[])
{
    int num;
    if (c == '|') {
        num = 0;
        for (int i = 9; i >= 0; i--) {
            if (status[i] == ALWAYS_ON)
                num |= (1 << i);
        }
    } else if (c == '&') {
        num = (1 << 10) - 1;
        for (int i = 9; i >= 0; i--) {
            if (status[i] == ALWAYS_OFF)
                num ^= (1 << i);
        }
    } else {
        num = 0;
        for (int i = 9; i >= 0; i--) {
            if (status[i] == ALWAYS_FLIP)
                num |= (1 << i);
        }
    }

    ans_cmd[index] = ii(c, num);
    printf("%c %d\n", c, num);
}

int main()
{
    int n;
    scanf("%d", &n);

    char cmd[10];
    int num;

    ii inp[n];
    int status[10];
    memset(status, -1, sizeof(status));
    for (int k = 0; k < n; k++) {
        scanf("%s %d", cmd, &num);

        inp[k] = ii(cmd[0], num);
        // printf("%c %d\n", inp[k].first, inp[k].second);

        int bit[10];
        get(bit, num);
        if (inp[k].first == '|') {
            for (int i = 0; i < 10; i++) {
                if (bit[i] == 0)
                    continue;

                status[i] = ALWAYS_ON;
            }
        } else if (inp[k].first == '&') {
            for (int i = 0; i < 10; i++) {
                if (bit[i] == 0) {
                    status[i] = ALWAYS_OFF;
                }
            }
        } else {
            for (int i = 0; i < 10; i++) {
                if (bit[i] == 0)
                    continue;

                if (status[i] == NONE) {
                    status[i] = ALWAYS_FLIP;
                } else if (status[i] == ALWAYS_ON)
                    status[i] = ALWAYS_OFF;
                else if (status[i] == ALWAYS_OFF)
                    status[i] = ALWAYS_ON;
                else
                    status[i] = NONE;
            }
        }
    }

    /*
    for(int i = 9; i >= 0; i--)
        printf("%d ", status[i]);
    printf("\n");
    */

    printf("3\n");
    print(0, '|', status);
    print(1, '&', status);
    print(2, '^', status);

    /*
    for (int i = 0; i <= 1023; i++) {
        int res = i;
        for (int j = 0; j < n; j++) {
            res = run(res, inp[j]);
        }

        int res1 = i;
        for(int j = 0; j < 3; j++) {
            res1 = run(res1, ans_cmd[j]);
        }

        if(res != res1)
            printf("%d %d %d\n", i, res, res1);
    }
    */

    return 0;
}
