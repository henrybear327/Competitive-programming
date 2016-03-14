#include <cstdio>

// this solution consists of checking non-distinct inputs
int main()
{
    int cases;
    scanf("%d", &cases);
    printf("Lumberjacks:\n");
    while (cases--) {
        int input[10];
        for (int i = 0; i < 10; i++)
            scanf("%d", &input[i]);

        bool error = false, is_increasing = (input[9] >= input[0]);

        for (int i = 1; i < 10; i++) {
            if (is_increasing) {
                if (input[i] < input[i - 1]) {
                    error = true;
                    break;
                }
            } else {
                if (input[i] > input[i - 1]) {
                    error = true;
                    break;
                }
            }
        }

        if (error == false)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }

    return 0;
}
