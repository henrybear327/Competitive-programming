#include <cstdio>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int byte;
    vector<char> ans;
    while (scanf("%d", &byte) == 1) {
        stack<int> s; // yoo! Striked by lightning
        while (byte) {
            s.push(byte % 10);
            byte /= 10;
        }
        int curr = 0;
        while (!s.empty()) {
            curr <<= 1;
            curr += s.top();
            s.pop();
        }
        ans.push_back(curr);
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%c", ans[i]);
    }
    printf("\n");

    return 0;
}
