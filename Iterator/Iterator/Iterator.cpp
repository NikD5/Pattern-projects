#include <iostream>

using namespace std;


class DataStack {
	int items_[10];
	int length_;

public:
	friend class StackIterator;
	DataStack()
	{
		length_ = -1;
	}

	void push(int value)
	{
		items_[++length_] = value;
	}

	int pop()
	{
		return items_[length_--];
	}
};

class StackIterator {
	const DataStack& stack_;
	int index_;

public:
	StackIterator(const DataStack& st) : stack_(st)
	{
		index_ = 0;
	}

	void operator++()
	{
		index_++;
	}

	int operator*()
	{
		return stack_.items_[index_];
	}

	bool operator()()
	{
		return index_ != stack_.length_ + 1;
	}
};

bool operator==(const DataStack& s1, const DataStack& s2)
{
	StackIterator it1(s1), it2(s2);

	for (; it1(); ++it1, ++it2) {
		if (*it1 != *it2)
			break;
	}

	return !it1() && !it2();
}

int main()
{
	setlocale(LC_ALL, "rus");


	DataStack stack1;

	for (int i = 1; i < 5; i++) {
		stack1.push(i);
	}

	DataStack stack2(stack1);

	cout << boolalpha << (stack1 == stack2) << endl;

	stack1.push(10);

	cout << boolalpha << (stack1 == stack2) << endl;

	return 0;
}