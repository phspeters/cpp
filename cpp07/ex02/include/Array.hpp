#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& src);
	~Array();
	
	Array<T>& operator=(const Array<T>& src);
	T &operator[](unsigned int i);

	unsigned int size() const { return (_size); }
	
private:
	T *_array;
	unsigned int _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &arr);

#endif