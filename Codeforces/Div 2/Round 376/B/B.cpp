#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int data[n];
    bool ok = true;
    for(int i = 0; i < n; i++)
        scanf("%d", &data[i]);

    for(int i = 0; i < n - 1; i++) {
        if(data[i] == 1 && data[i + 1] == 0)
            ok = false;
        if(data[i] % 2 == data[i + 1] % 2)
            data[i] = data[i + 1] = 0;
        else {
            data[i] = 0;
            data[i + 1] = 1;
        }
    }

    if(data[n - 1] % 2 == 1)
        ok = false;

    printf("%s\n", ok ? "YES" : "NO");

    return 0;
}
