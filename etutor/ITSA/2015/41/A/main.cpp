#include <cstdio>
#include <cstring>

const char *note[] = {"C",  "C#", "D",  "D#", "E",  "F",
                      "F#", "G",  "G#", "A",  "A#", "B"
                     };

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        char input[100];
        scanf("%s", input);

        bool is_minor = input[strlen(input) - 1] == 'm';
        if (is_minor)
            input[strlen(input) - 1] = '\0';

        int match = -1;
        for (int i = 0; i < 12; i++) {
            if (!strcmp(input, note[i])) {
                match = i;
                break;
            }
        }

        printf("%s ", note[match]);
        if (is_minor) {
            match = match + 3 >= 12 ? match + 3 - 12 : match + 3;
        } else {
            match = match + 4 >= 12 ? match + 4 - 12 : match + 4;
        }
        printf("%s ", note[match]);

        if (is_minor) {
            match = match + 4 >= 12 ? match + 4 - 12 : match + 4;
        } else {
            match = match + 3 >= 12 ? match + 3 - 12 : match + 3;
        }
        printf("%s\n", note[match]);
    }

    return 0;
}
