class Solution {
public:
    int lengthOfLastWord(string s) {
        int mx = 0;

        char* tok = strtok(s.data(), " "); // wow
        while(tok != NULL) {
            mx = (int)strlen(tok);
            tok = strtok(NULL, " ");
        }

        return mx;
    }
};
