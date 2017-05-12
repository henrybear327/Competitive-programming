#include <bits/stdc++.h>

using namespace std;

struct Entry {
    string title;
    string author;
    bool inStock;
    bool pending;

    Entry(string title, string author, bool inStock)
    {
        this->title = title;
        this->author = author;
        this->inStock = inStock;
        this->pending = false;
    }

    bool operator<(const Entry &other) const
    {
        if (author == other.author)
            return title < other.title;
        return author < other.author;
    }
};

void clean(char *str)
{
    int len = strlen(str);
    while (str[len - 1] == '\n' || str[len - 1] == '\r') {
        str[len - 1] = '\0';
        len--;
    }
}

int main()
{
    char inp[10000];
    vector<Entry> data;
    while (fgets(inp, 10000, stdin) != NULL) {
        if (strcmp(inp, "END\n") == 0)
            break;
        clean(inp);

        int len = strlen(inp);

        int quote = -1;
        for (int i = 0; i < len; i++) {
            if (inp[i] == '"') {
                if (quote == -1)
                    quote = i;
                else {
                    quote = i;
                    break;
                }
            }
        }
        // printf("quote %d\n", quote);

        // [starting, ending) = [1, quote)
        char title[10000] = {'\0'}; // bitch, \0 is required
        strncpy(title, inp + 1, quote - 1);

        // [quote + 5, len)
        char author[10000] = {'\0'};
        strncpy(author, inp + quote + 5, len - (quote + 5));

        // printf("%s\n%s\n\n", title, author);
        data.push_back(Entry(title, author, true));
    }

    sort(data.begin(), data.end());
    // for(auto i : data) {
    // printf("title %s, author %s, inStock %d\n", i.title.c_str(),
    // i.author.c_str(), i.inStock);
    // }

    while (fgets(inp, 10000, stdin) != NULL) {
        if (inp[0] == 'E')
            break;

        clean(inp);

        if (inp[0] == 'B') {
            // borrow [8, len)
            string inp1 = inp;
            string title = inp1.substr(8, inp1.length() - 9);
            // cout << "borrow " << title << endl;

            for (int i = 0; i < (int)data.size(); i++)
                if (data[i].title == title) {
                    // cout << i << endl;
                    data[i].inStock = false;
                    data[i].pending = false;
                }
        } else if (inp[0] == 'R') {
            // return [8, len - 1)
            string inp1 = inp;
            string title = inp1.substr(8, inp1.length() - 9);
            // cout << "return " << title << endl;

            for (int i = 0; i < (int)data.size(); i++)
                if (data[i].title == title) {
                    // cout << i << endl;
                    data[i].pending = true;
                }
        } else {
            // shelve
            int prev = -1;
            for (int i = 0; i < (int)data.size(); i++) {
                if (data[i].inStock)
                    prev = i;
                if (data[i].pending == true) {
                    if (prev == -1)
                        printf("Put \"%s\" first\n", data[i].title.c_str());
                    else
                        printf("Put \"%s\" after \"%s\"\n", data[i].title.c_str(),
                               data[prev].title.c_str());

                    data[i].pending = false;
                    data[i].inStock = true;
                    prev = i;
                }
            }
            printf("END\n");
        }
    }

    return 0;
}
