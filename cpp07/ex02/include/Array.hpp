#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array<T>& other);
	~Array();

	Array<T>& operator=(const Array<T>& other);
	T &operator[](unsigned int index) const;

	size_t size() const;
	
private:
	T *_array;
	size_t _size;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &arr);

# include "Array.tpp"

#endif