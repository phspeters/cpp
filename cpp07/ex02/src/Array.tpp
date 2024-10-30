#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& src) : _array(new T[src._size]), _size(src._size) {
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = src._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src) {
	if (this != &src) {
		delete [] _array;
		_array = new T[src._size];
		_size = src._size;

		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = src._array[i];
		}
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= _size) {
		throw std::out_of_range("Index out of range");
	}
	
	return (_array[i]);
}
