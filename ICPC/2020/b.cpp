#include <bits/stdc++.h>

using namespace std;

int cal(vector<int> num, vector<char> _op) {
    stack<int> val;

    val.push(num[0]);
    for(int i = 1; i < (int)num.size(); i++) {
        char op = _op[i - 1];
        if(op == '+')
            val.push(num[i]);
        else if (op == '-')
            val.push(num[i] * -1);
        else {
            int pre = val.top();
            val.pop();
            val.push(pre * num[i]);
        }
    }

    int ret = 0;
    while(val.size() > 0) {
        ret += val.top();
        val.pop();
    }

    return ret;
}

int main()
{
    int inp[4];
    for(int i = 0; i < 4; i++) 
        scanf("%d", &inp[i]);

    sort(inp, inp + 4);

    set<int> val;

    do {
        /*
           0 +
           1 - 
           2 *
         */
        const char* operations = "+-*";
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++) {
                    // case 1 _ _ _ _
                    val.insert(cal(vector<int>{inp[0], inp[1], inp[2], inp[3]}, vector<char>{operations[i], operations[j], operations[k]}));

                    // case 2-1 __ _ _
                    val.insert(cal(vector<int>{inp[0] * 10 + inp[1], inp[2], inp[3]}, vector<char>{operations[i], operations[j]}));
                    // case 2-2 _ __ _
                    val.insert(cal(vector<int>{inp[0], inp[1] * 10 + inp[2], inp[3]}, vector<char>{operations[i], operations[j]}));
                    // case 2-3 _ _ _ _
                    val.insert(cal(vector<int>{inp[0], inp[1], inp[2] * 10 + inp[3]}, vector<char>{operations[i], operations[j]}));

                    // case 3 __ __ 
                    val.insert(cal(vector<int>{inp[0] * 10 + inp[1], inp[2] * 10 + inp[3]}, vector<char>{operations[i]}));

                    // case 4 ___ _
                    val.insert(cal(vector<int>{inp[0] * 100 + inp[1] * 10 + inp[2], inp[3]}, vector<char>{operations[i]}));
                }
    } while(next_permutation(inp, inp + 4));

    int ans = 0;
    for(auto i : val)
        if(i >= 0)
            ans++;
    printf("%d\n", ans);

    return 0;
}
