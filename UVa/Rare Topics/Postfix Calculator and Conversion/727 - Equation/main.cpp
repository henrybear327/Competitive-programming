#include <cstdio>
#include <stack>

using namespace std;

typedef enum {
    lparen,
    rparen,
    plus,
    minus,
    multiply,
    divide,
    mod,
    operand
} Precedence;

/*in-stack precedence*/
const int isp[7] = {0, 19, 12, 12, 13, 13, 13};
/*in-coming precedence*/
const int icp[7] = {20, 19, 12, 12, 13, 13, 13};

const char sign[7] = {'(', ')', '+', '-', '*', '/', '%'};

/*
Think of these two cases, try them both with the help of isp/icp and without.
The difference will be clear.

a*(b+c*a)*d
a*(b*c+a)*d
*/

Precedence get_next_token(char c)
{
    switch (c) {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '*':
        return multiply;
    case '/':
        return divide;
    case '%':
        return mod;
    default:
        return operand;
    }
}

int main()
{
    char inp[10];

    int n;
    fgets(inp, 10, stdin);
    sscanf(inp, "%d", &n);
    fgets(inp, 10, stdin);

    bool first = true;
    while (n--) {
        if (first)
            first = false;
        else
            printf("\n");

        stack<int> s;
        while (fgets(inp, 10, stdin) != NULL && inp[0] != '\n') {
            /*By 3 cases*/
            Precedence token = get_next_token(inp[0]);

            if (token == operand) {
                // number, just print it!
                printf("%c", inp[0]);
            } else if (token == rparen) {
                // encounter rparen
                while (s.top() != lparen) {
                    printf("%c", sign[s.top()]);
                    s.pop();
                }
                s.pop();
            } else {
                // if isp >= icp, pop it first
                while (!s.empty() && isp[s.top()] >= icp[token]) {
                    printf("%c", sign[s.top()]);
                    s.pop();
                }

                s.push(token);
            }
        }

        while (!s.empty()) {
            printf("%c", sign[s.top()]);
            s.pop();
        }
        printf("\n");
    }

    return 0;
}
