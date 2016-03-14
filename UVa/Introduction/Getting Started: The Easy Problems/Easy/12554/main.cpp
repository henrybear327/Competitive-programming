#include <cstdio>

int main()
{
    int people;
    scanf("%d", &people);
    char name[102][110];

    for (int i = 0; i < people; i++)
        scanf("%s", name[i]);

    const char *song[5] = {"Happy", "birthday", "to", "you", "Rujia"};

    int times = (people / 16 + 1) * 16;

    for (int i = 0; i < times; i++) {
        printf("%s: %s\n", name[i % people],
               i > 0 && i % 16 == 11 ? song[4] : song[i % 4]);
    }

    return 0;
}
