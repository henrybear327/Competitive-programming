// sort algorithm example
#include <iostream>  // std::cout
#include <algorithm> // std::sort
#include <vector>    // std::vector

// Equivalent elements are not guaranteed to keep their original relative order
// (see stable_sort).

using namespace std;

bool myfunction(int i, int j)
{
    return (i < j);
}

struct myclass {
    bool operator()(int i, int j) {
        return (i < j);
    }
} myobject;

void print(vector<int> myvector)
{
    printf("Result:");
    for (auto it = myvector.begin(); it != myvector.end(); it++)
        cout << ' ' << *it;
    cout << '\n';
}

int main()
{
    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    vector<int> myvector(myints, myints + 8); // 32 71 12 45 26 80 53 33
    print(myvector);

    // using default comparison (operator <):
    sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71)26 80 53 33
    print(myvector);

    // using function as comp
    sort(myvector.begin() + 4, myvector.end(),
         myfunction); // 12 32 45 71(26 33 53 80)
    print(myvector);

    // using object as comp
    sort(myvector.begin(), myvector.end(), myobject); //(12 26 32 33 45 53 71 80)
    print(myvector);

    return 0;
}
