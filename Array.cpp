//
// Created by Computer on 14.11.2018.
//

#include "Array.h"

template<typename T>
Array<T>::Array(size_t size, const T &value) {
    _size = size;
    data = new byte[_size * sizeof(T)];
    T *ptr = (T *) data;
    for (size_t i = 0; i < _size; ++i)
        new(ptr + i) T(value);
}

template<typename T>
Array<T>::~Array() {
    T *ptr = (T *) data;
    for (size_t i = 0; i < _size; ++i)
        ptr[i].~T();
    delete[] data;
}

template<typename T>
size_t Array<T>::size() const {
    return _size;
}

template<typename T>
T &Array<T>::operator[](size_t i) {
    T *ptr = (T *) data;
    return *(ptr + i);
}

template<typename T>
const T &Array<T>::operator[](size_t i) const {
    T *ptr = (T *) data;
    return *(ptr + i);
}

template<typename T>
void Array<T>::swap(Array<T> &arr) {
    std::swap(_size, arr._size);
    std::swap(data, arr.data);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &arr) {
    if (this != &arr) {
        Array<T> temp(arr);
        temp.swap(*this);
    }
    return *this;
}

template<typename T>
Array<T>::Array(const Array &arr) {
    _size = arr._size;
    data = new byte[_size * sizeof(T)];
    T *ptr = (T *) data;
    for (size_t i = 0; i < _size; ++i)
        new(ptr + i) T(arr[i]);
}

template<typename T>
void Array<T>::print() {
    for (size_t i = 0; i < size(); ++i)
        cout << *((T *) data + i);
    cout << endl;
}

template<typename Type>
Type minimum(const Array<Type> &array, bool (*f)(Type, Type)) {
    int minIdx = 0;
    for (int i = 1; i < array.size(); ++i) {
        if (!f(array[minIdx], array[i])) {
            minIdx = i;
        }
    }
    return array[minIdx];
}

template<typename Type1, typename Type2>
Type1 minimum(const Array<Type1> &array, Type2 greater) {
    int minIdx = 0;
    for (int i = 1; i < array.size(); ++i) {
        if (!greater(array[minIdx], array[i])) {
            minIdx = i;
        }
    }
    return array[minIdx];
}

template<typename T>
void flatten(const Array<T> &array, std::ostream &out) {
    for (size_t i = 0; i != array.size(); ++i) {
        out << array[i] << " ";
    }
}

template<typename T>
void flatten(const Array<Array<T> > &array, std::ostream &out) {
    for (size_t i = 0; i != array.size(); ++i) {
        flatten(array[i], out);
    }
}


