#include <cstdio>
#include <string>
#include <list>

using namespace std;

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        int n, k;
        while (scanf("%d %d", &n, &k) == 2) {
            list<string> data;
            for (int i = 0; i < n; i++) {
                char inp[100];
                scanf("%s", inp);
                data.push_back(inp);
            }

            int idx = 0; // use 0-based
            while (data.size() > 1) {
                /*
                it = it + 10;
                wrong because of the doubly linked list property. Use advance()
                http://stackoverflow.com/questions/10564222/error-no-match-for-operator-for-list-iterator
                */
                idx = (idx + k - 1) % data.size();
                list<string>::iterator it = data.begin();
                advance(it, idx);
                it = data.erase(it);
            }
            list<string>::iterator it = data.begin();
            printf("%s\n", (*it).c_str());
        }
    }

    return 0;
}
