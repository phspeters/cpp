#include "MutantStack.hpp"
#include <list>

void subjectTests(void) {
	std::cout << "SUBJECT TESTS\n\n";

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "mstack.top(): "<< mstack.top() << std::endl;

	mstack.pop();

	std::cout << "mstack.size(): " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << ", ";
	}
	std::stack<int> s(mstack);
	std::cout << '\n';
}

void subjectTestsWithList(void) {
	std::cout << "SUBJECT TESTS WITH LIST\n\n";

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << "list.back(): "<< list.back() << std::endl;

	list.pop_back();

	std::cout << "list.size(): " << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << ", ";
	}
	std::list<int> s(list);
	std::cout << '\n';
}

void canonicalTests(void) {
	std::cout << "CANONICAL TESTS\n\n";
	std::cout << "---> Default constructor:\n";
	MutantStack<int> mstack;
	std::cout << "mstack: " << mstack << '\n';
	std::cout << '\n';

	std::cout << "... Pushing 5, 17 ...\n";
	mstack.push(5);
	mstack.push(17);
	std::cout << '\n';

	std::cout << "---> Copy constructor:\n";
	std::cout << "mstack: " << mstack << '\n';
	std::cout << '\n';

	MutantStack<int> mstack2(mstack);
	std::cout << "mstack2: " << mstack2 << '\n';
	std::cout << '\n';

	std::cout << "---> Assignment operator:\n";
	MutantStack<int> mstack3;
	std::cout << "... Assigning mstack2 to mstack3 ...\n";
	std::cout << '\n';

	mstack3 = mstack2;
	std::cout << "mstack3: " << mstack3;
	std::cout << '\n';
}

void methodsTests(void) {
	std::cout << "METHODS TESTS\n\n";

	std::cout << "... Creating empty MutantStack ...\n";
	MutantStack<int> mstack;
	std::cout << "mstack.empty(): " << (mstack.empty() ? "true" : "false") << '\n';
	std::cout << '\n';

	std::cout << "... Pushing 5, 17, 3, 5, 737, 0 ...\n";
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << '\n';

	std::cout << "---> Methods:\n";
	std::cout << "mstack.top(): " << mstack.top() << '\n';
	std::cout << "mstack.size(): " << mstack.size() << '\n';
	std::cout << "mstack.empty(): " << (mstack.empty() ? "true" : "false") << '\n';
	std::cout << "mstack: " << mstack << '\n';
	std::cout << '\n';

	std::cout << "... Poppping top element ...\n";
	mstack.pop();
	std::cout << '\n';

	std::cout << "mstack.top(): " << mstack.top() << '\n';
	std::cout << "mstack.size(): " << mstack.size() << '\n';
	std::cout << "mstack: " << mstack << '\n';
	std::cout << '\n';

	std::cout << "... Pushing 42 ...\n";
	mstack.push(42);
	std::cout << '\n';

	std::cout << "mstack.top(): " << mstack.top() << '\n';
	std::cout << "mstack.size(): " << mstack.size() << '\n';
	std::cout << "mstack: " << mstack;
	std::cout << '\n';
}

void iteratorsTests(void) {
	std::cout << "ITERATORS TESTS\n\n";

	std::cout << "... Creating MutantStack and pushing 5, 17, 3, 5, 737, 0 ...\n";
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << '\n';

	std::cout << "---> Iterating with iterators:\n";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	int index = 0;
	while(it != ite) {
		std::cout << "mstack[" << index++ << "]: " << *(it++) << '\n';
	}
	std::cout << '\n';

	std::cout << "... Decrementing iterator twice ...\n";
	--it;
	--it;
	std::cout << "it: " << *it << '\n';
	std::cout << '\n';

	std::cout << "... Iterating with const iterators ...\n";
	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	index = 0;
	while(cit != cite) {
		std::cout << "mstack[" << index++ << "]: " << *(cit++) << '\n';
	}
	std::cout << '\n';

	std::cout << "... Decrementing const iterator once ...\n";
	--cit;
	std::cout << "cit: " << *cit << '\n';
	std::cout << '\n';
}

int main(void) {
	subjectTests();
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	subjectTestsWithList();
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	canonicalTests();
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	methodsTests();
	std::cout << "\n--------------------------------------------------------------------------------\n\n";
	iteratorsTests();
}
