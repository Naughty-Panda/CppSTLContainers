//////////////////////////////////////////
//	C++ STL Containers
//	Naughty Panda @ 2021
//////////////////////////////////////////

#include <iostream>
#include <list>
#include <algorithm>

//////////////////////////////////////////
//	3.1
//////////////////////////////////////////

void calculate_next(std::list<int>& l) {

	int sum{ 0 };
	int size{ static_cast<int>(l.size()) };
	std::for_each(std::begin(l), std::end(l), [&sum](const int& i) { sum += i; });
	l.push_back(sum / size);
}

template <typename T>
void print(const std::list<T>& l) {

	std::copy(std::begin(l), std::end(l), std::ostream_iterator<T>(std::cout, " "));
}

template <typename T>
void rprint(const std::list<T>& l) {

	std::copy(std::rbegin(l), std::rend(l), std::ostream_iterator<T>(std::cout, " "));
}


int main() {

	std::list<int> l1{ 0,1,2,3,4,5,6,7,8,9 };
	
	std::cout << "Default list: ";
	print(l1);
	std::cout << "\nReversed list: ";
	rprint(l1);

	calculate_next(l1);
	std::cout << "\nModified list: ";
	print(l1);

	return 0;
}
