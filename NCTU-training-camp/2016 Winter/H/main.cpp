#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const char *command = {"UDRLudrl"};
char inp[100000 + 100];
int x, y;
void move(char command, int pos, int len)
{
    int num = 0;
    for(int i = pos - len; i <= pos - 1 ; i++) {
        num *= 10;
        num += inp[i] - '0';
    }
    //printf("%d\n", num);
    
    if(command == 'U' || command == 'u') {
        y += num;
    } else if(command == 'D' || command == 'd') {
        y -= num;
    } else if(command == 'L' || command == 'l') {
        x -= num;
    } else {
        x += num;
    }
}

int main()
{
    int ncase;
    scanf("%d", &ncase);

    while(ncase--) {
        x = 0, y = 0;
        scanf("%s", inp);
        //printf("=====\n");
        
        int len = strlen(inp);
        int num_len = 0;
        for(int i = 0; i < len; i++) {
            // if char
            bool has_command = false;
            if(('a' <= inp[i] && inp[i] <= 'z') 
                || ('A' <= inp[i] && inp[i] <= 'Z')) {
                for(int j = 0; j < 8; j++) {
                    if(inp[i] == command[j]) {
                        has_command = true;
                        break;
                    }
                }
                
                if(has_command == false) {
                    num_len = 0;
                } else {
                    if(num_len == 0)
                        continue;
                    //printf("%c\n", inp[i]);
                    move(inp[i], i, num_len); // ?
                    num_len = 0;
                }
            } else {
                 if(num_len <= 1) {
                     num_len++;
                 } else {
                     num_len = 0;
                 }
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}