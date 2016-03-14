#include <cstdio>
#include <cstring>

// #include <iostream> // for cin/cout
// #include <iomanip>  // for fixed, setprecision

#include <string>
#include <map>

using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int cases;
    scanf("%d", &cases);
    getchar();
    getchar();
    while (cases--) {
        char inp[100];
        int total = 0;
        map<string, int> data;

        while (fgets(inp, 100, stdin) != NULL && inp[0] != '\n') {
            inp[strlen(inp) - 1] = '\0';
            data[inp]++;
            total++;
        }

        for (map<string, int>::iterator i = data.begin(); i != data.end(); i++) {
            double ans = (double)(i->second) / total * 100;
            // cout << i->first << " " << fixed << setprecision(4) << ans << '\n';
            printf("%s %.4f\n", i->first.c_str(), ans);
        }

        if (cases != 0)
            // cout << endl;
            printf("\n");
    }

    return 0;
}
