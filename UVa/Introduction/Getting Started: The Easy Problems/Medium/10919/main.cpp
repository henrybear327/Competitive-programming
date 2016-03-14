#include <cstdio>

int main()
{
    int course, category;
    while (scanf("%d %d", &course, &category) == 2 && course != 0) {
        int course_list[course];
        for (int i = 0; i < course; i++)
            scanf("%d", &course_list[i]);

        bool flag = true;
        for (int i = 0; i < category; i++) {
            int total, req;
            scanf("%d %d", &total, &req);

            for (int j = 0; j < total; j++) {
                int tmp;
                scanf("%d", &tmp);

                for (int k = 0; k < course; k++) {
                    if (course_list[k] == tmp) {
                        req--;
                        break;
                    }
                }
            }

            if (req > 0) { // come on, man!
                flag = false;
            }
        }

        if (flag)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
