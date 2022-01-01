class Solution {
public:
    int strStr(string haystack, string needle) {
        const char* tmp = haystack.c_str();
        const char* start = strstr(tmp, needle.c_str());
        if(start != NULL) {
            return start - tmp;
        }

        return -1;
    }
};
