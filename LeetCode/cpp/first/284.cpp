#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;

// tree node stuff here...
#endif

static int __initialSetup = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}
();

// handle special cases first
// [], "", ...
// range of input?
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator
{
	struct Data;
	Data *data;

public:
	Iterator(const vector<int> &nums);
	Iterator(const Iterator &iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
	PeekingIterator(const vector<int> &nums) : Iterator(nums)
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek()
	{
		return Iterator(*this).next(); // create a new object, and then call next on it.
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
	{
		return Iterator::next();
	}

	bool hasNext() const
	{
		return Iterator::hasNext();
	}
};

#ifdef LOCAL
int main()
{
	return 0;
}
#endif