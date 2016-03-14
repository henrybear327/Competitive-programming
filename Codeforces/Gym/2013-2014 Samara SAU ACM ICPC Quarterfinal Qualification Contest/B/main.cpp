#include <map>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int cases;
    while(scanf("%d", &cases) != EOF) {
        char input[1000100];
        fgets(input, 1000100, stdin);
        map<vector<int>, long long int> data;
        for(int i = 0; i < cases; i++) {
            fgets(input, 1000100, stdin);

            int idx = 1, len = strlen(input) - 1;
            int book[26] = {0};
            vector<int> encoded;

            //unordered_map can't use vector as key
            for(int j = 0; j < len; j++) {
                if(book[input[j] - 'a'] == 0) {
                    book[input[j] - 'a'] = idx;
                    idx++;
                }

                encoded.push_back(book[input[j] - 'a']); // old code using string with book[input[j] - 'a'] + '0' will cause problem if the idx >= 10
            }

            data[encoded]++;
        }

        long long int ans = 0;
        for(auto i = data.begin(); i != data.end(); i++) {
            if(i -> second > 1) {
                ans += ((i -> second) * (i -> second - 1) / 2);
            }
        }

        printf("%I64d\n", ans);
    }

    return 0;
}
