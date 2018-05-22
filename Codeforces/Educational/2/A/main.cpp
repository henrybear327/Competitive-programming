#include <bits/stdc++.h>
using namespace std;

int main()
{
    char inp[100010];
    scanf("%s", inp);

    string a, b;

    int len = strlen(inp);
    string tmp;
    bool is_number = true;
    for (int i = 0; i <= len; i++) {
        if (inp[i] != ',' && inp[i] != ';' && i != len) {
            tmp.push_back(inp[i]);
            if (isdigit(inp[i]) == false && is_number == true)
                is_number = false;
        } else {
            if (tmp.size() == 0) {
                b.push_back(',');
            } else {
                if (is_number == true) {
                    if (tmp[0] == '-')
                        is_number = false;
                    if (tmp.size() > 1 && tmp[0] == '0')
                        is_number = false;
                }

                if (is_number) {
                    a.append(tmp);
                    a.push_back(',');
                } else {
                    b.append(tmp);
                    b.push_back(',');
                }
            }

            is_number = true;
            tmp.clear();
        }
    }

    if (a.empty())
        printf("-\n");
    else {
        a.pop_back();
        printf("\"%s\"\n", a.c_str());
    }

    if (b.empty())
        printf("-\n");
    else {
        b.pop_back();
        printf("\"%s\"\n", b.c_str());
    }

    return 0;
}
