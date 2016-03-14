#include <cstdio>
#include <cstring>
#include <climits>

typedef struct info {
    char name[100];
    int mark;
    double price;
} Info;

int main()
{
    int req, proposal, index = 1;
    while (scanf("%d %d", &req, &proposal) == 2 && req != 0 && proposal != 0) {
        if (index != 1)
            printf("\n");

        getchar();

        char req_string[req][100];
        for (int i = 0; i < req; i++) {
            fgets(req_string[i], 100, stdin);
        }

        Info ans[proposal];
        memset(ans, 0, sizeof(ans));

        int max = -1, min_price = INT_MAX, ans_i;
        for (int i = 0; i < proposal; i++) {
            fgets(ans[i].name, 100, stdin);

            scanf("%lf %d", &ans[i].price, &ans[i].mark);
            getchar();

            for (int j = 0; j < ans[i].mark; j++) {
                char inp[100];
                fgets(inp, 100, stdin);
            }

            // printf("%d %d %f\n", i, ans[i].mark, ans[i].price);
            if (ans[i].mark > max) {
                max = ans[i].mark;
                min_price = ans[i].price;
                ans_i = i;
            }

            if (ans[i].mark == max && min_price > ans[i].price) { // must be carefully thought of
                min_price = ans[i].price;
                ans_i = i;
            }
        }

        printf("RFP #%d\n", index++);
        printf("%s", ans[ans_i].name);
    }

    return 0;
}
