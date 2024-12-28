#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : _array(new T[other._size]), _size(other._size) {
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete [] _array;
		_array = new T[other._size];
		_size = other._size;

		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = other._array[i];
		}
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::out_of_range("Index out of range");
	}
	
	return (_array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
	if (index >= _size) {
		throw std::out_of_range("Index out of range");
	}
	
	return (_array[index]);
}

template <typename T>
size_t Array<T>::size() const {
	return (_size);
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &arr) {
	out << "{ ";
	for (size_t i = 0; i < arr.size(); i++) {
		out << arr[i];
		if (i + 1 < arr.size()) {
			out << ", ";
		}
	}
	out << " }";
	return (out);
}

#endif