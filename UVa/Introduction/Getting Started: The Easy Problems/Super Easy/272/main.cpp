#include <cstdio>
#include <cstring>

int main()
{
    bool flag = false;
    char input[1000];
    while (fgets(input, 1000, stdin) != NULL) {
        int len = strlen(input);
        for (int i = 0; i < len; i++) {
            if (input[i] == '"' && flag == false) {
                flag = true;
                printf("``");
            } else if (input[i] == '"' && flag == true) {
                flag = false;
                printf("''");
            } else {
                printf("%c", input[i]);
            }
        }
    }

    return 0;
}
