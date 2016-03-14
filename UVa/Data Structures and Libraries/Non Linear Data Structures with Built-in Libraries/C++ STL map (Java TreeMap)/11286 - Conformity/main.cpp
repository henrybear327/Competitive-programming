#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int cases;
    while (scanf("%d", &cases) == 1 && cases) {
        unordered_map<string, int> data;
        while (cases--) {
            vector<int> input;
            for (int i = 0; i < 5; i++) {
                int tmp;
                scanf("%d", &tmp);
                input.push_back(tmp);
            }

            sort(input.begin(), input.end());
            string tmp = "a";
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 3; j++) {
                    tmp += (input[i] % 10 + '0');
                    input[i] /= 10;
                }
            }

            data[tmp]++;
        }

        int max = -1, max_cnt = 0;
        for (auto i = data.begin(); i != data.end(); i++) {
            if (i->second > max) {
                max = max_cnt = i->second;
            } else if (i->second == max) {
                max_cnt += i->second;
            }
        }

        printf("%d\n", max_cnt);
    }

    return 0;
}
