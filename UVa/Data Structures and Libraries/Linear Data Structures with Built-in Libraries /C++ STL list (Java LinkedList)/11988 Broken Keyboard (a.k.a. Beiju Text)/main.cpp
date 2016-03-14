#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct ans {
    char c;
    struct ans *next;
} Ans;

Ans *create(char c)
{
    Ans *tmp = (Ans *)malloc(sizeof(Ans));
    tmp->next = NULL;
    tmp->c = c;

    return tmp;
}

Ans *head = NULL, *curr = NULL, *end = NULL, *prev = NULL;
bool insert_in_front = false;
void insert(char c)
{
    if (curr == NULL) { // first time, need to init
        if (c != '[' && c != ']') {
            curr = create(c);
            head = curr;
            end = curr;
        }
    } else {
        if (c == '[') {
            curr = head;
            insert_in_front = true;

            prev = NULL;
        } else if (c == ']') {
            curr = end;
            insert_in_front = false;
        } else {
            if (insert_in_front == true) {
                Ans *tmp = create(c);

                if (prev == NULL) {
                    tmp->next = head;
                    head = tmp;
                } else {
                    tmp->next = prev->next;
                    prev->next = tmp;
                }

                prev = tmp;
            } else {
                Ans *tmp = create(c);
                end->next = tmp;
                end = tmp;
                curr = tmp;
            }
        }
    }
}

int main()
{
    char input[100100];
    while (fgets(input, 100100, stdin) != NULL) {
        head = curr = end = NULL;
        insert_in_front = false;

        for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            insert(input[i]);

            /*
            Ans *test = head;
            while (test) {
                printf("%c", test->c);
                test = test->next;
            }
            printf("\n");
            */
        }

        curr = head;
        while (curr) {
            printf("%c", curr->c);
            curr = curr->next;
        }
        printf("\n");
    }
    return 0;
}
