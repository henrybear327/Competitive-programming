#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int main()
{
    map<char, char> m;
    m['A'] = 'T';
    m['T'] = 'A';
    m['C'] = 'G';
    m['G'] = 'C';

    char c;
    scanf("%c", &c);

    printf("%c\n", m[c]);

    return 0;
}
