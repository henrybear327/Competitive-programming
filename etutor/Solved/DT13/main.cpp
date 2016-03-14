#include <cstdio>
#include <cctype>
#include <stack>

using namespace std;

int main()
{
    char inp[10000];
    while (scanf("%s", inp) == 1 && inp[0] != '0') {
        stack<int> s;
        for (int i = 0; inp[i] != '\0'; i++) {
            if (isdigit(inp[i])) {
                s.push(inp[i] - '0');
            } else {
                int op1, op2;
                switch (inp[i]) {
                case '+':
                    op2 = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.push(op1 + op2);
                    break;
                case '-':
                    op2 = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.push(op1 - op2);
                    break;
                case '*':
                    op2 = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.push(op1 * op2);
                    break;
                case '/':
                    op2 = s.top();
                    s.pop();
                    op1 = s.top();
                    s.pop();
                    s.push(op1 / op2);
                    break;
                default:
                    break;
                }
            }
        }

        printf("%d\n", s.top());
    }

    return 0;
}
