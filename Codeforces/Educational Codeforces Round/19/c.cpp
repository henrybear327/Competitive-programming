#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    char inp[100000];
    scanf("%s", inp);
    
    int len = strlen(inp);
    int cnt[26] = {0};
    for(int i = 0; i < len; i++)
        cnt[inp[i] - 'a']++;
    
    int qPtr = 0;
    stack<char> s;
    string ans = "";
    while(qPtr < len) {
        if(s.empty() == true) {
            s.push(inp[qPtr]);  
            cnt[inp[qPtr] - 'a']--;
            qPtr++;
        } else {
            bool has = false;
            int cur = s.top() - 'a';
            for(int i = cur - 1; i >= 0; i--) {
                if(cnt[i] > 0) {
                    has = true;
                    break;
                }
            }
            if(has) {
                s.push(inp[qPtr]);  
                cnt[inp[qPtr] - 'a']--;
                qPtr++;
            } else {
                ans += s.top();
                s.pop();
            }
        }
    }
    
    while(s.empty() == false) {
        ans += s.top();
        s.pop();
    }
    printf("%s\n", ans.c_str());
   
    return 0;
}