//////////////////////////////////////////
//	C++ STL Containers
//	Naughty Panda @ 2021
//////////////////////////////////////////

#include <iostream>
#include <list>
#include <algorithm>
#include <initializer_list>

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

//////////////////////////////////////////
//	3.3
//////////////////////////////////////////

template <typename ValueType>
class MyIterator : public std::iterator<std::input_iterator_tag, ValueType> {

	//friend class MyContainer;
private:
	ValueType* ptr;

public:
	MyIterator(ValueType* p) : ptr(p) {}
	MyIterator(const MyIterator& it) : ptr(it.ptr) {}

	bool operator ==(const MyIterator& it) const { return ptr == it.ptr; }
	bool operator !=(const MyIterator& it) const { return ptr != it.ptr; }

	MyIterator& operator++() { ++ptr; return *this; }
	typename MyIterator::reference operator*() const { return *ptr; }
};

template <typename T>
class MyContainer {

private:
	std::unique_ptr<T[]> data;
	const size_t size;

public:
	MyContainer(std::initializer_list<T> values) : size(values.size()), data(new T[size]) { std::copy(std::begin(values), std::end(values), data.get()); }

	MyIterator<T> begin() { return MyIterator<T>(data.get()); }
	MyIterator<T> end() { return MyIterator<T>(data.get() + size); }

	MyIterator<const T> begin() const { return MyIterator<const T>(data.get()); }
	MyIterator<const T> end() const { return MyIterator<const T>(data.get() + size); }
};


int main() {

	std::list<int> l1{ 0,1,2,3,4,5,6,7,8,9 };
	
	std::cout << "Default list: ";
	print(l1);
	std::cout << "\nReversed list: ";
	rprint(l1);

	calculate_next(l1);
	std::cout << "\nModified list: ";
	print(l1);

	MyContainer<int> cnt{ 3,5,7,9 };

	// TODO: fix heap corruption
	//std::cout << *cnt.begin();

	return 0;
}
