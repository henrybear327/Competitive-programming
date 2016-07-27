#include <bits/stdc++.h>

using namespace std;

#define N 200100

string split(string s)
{
    if(s.length() % 2 == 1)
	return s;

    string str1 = split(s.substr(0, s.length() / 2));
    string str2 = split(s.substr(s.length() / 2, s.length() / 2));
     
    if(str1 <= str2) {
	return str1 + str2;
    } else {
	return str2 + str1;
    }
}

int main()
{
    char inp[N];
    scanf("%s", inp);
    string s1 = inp;
    scanf("%s", inp);
    string s2 = inp;

    if(s1.length() % 2 == 0 && s1.length() % 2 == 0 && s1.length() == s2.length() && split(s1) == split(s2))
	printf("YES\n");
    else if(s1.length() % 2 == 1 && s2.length() % 2 == 1 && s1.length() == s2.length() && s1 == s2)
	printf("YES\n");
    else
	printf("NO\n");

    return 0;
}
