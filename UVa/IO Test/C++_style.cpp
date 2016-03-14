#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b;
    for (int i = 0; i < 99999999; i++) {
        cin >> a >> b;
        cout << (a - b) << '\n';
    }

    return 0;
}
