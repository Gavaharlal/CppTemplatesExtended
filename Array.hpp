#include "Array.h"

using std::cout;
using std::endl;

template<typename T>
Array<T>::Array(size_t size, const T &value) {
    mArraySize = size;
    mData = new byte[mArraySize * sizeof(T)];
    T *ptr = (T *) mData;
    for (size_t i = 0; i < mArraySize; ++i) {
        new(ptr + i) T(value);
    }
}

template<typename T>
Array<T>::~Array() {
    T *ptr = (T *) mData;
    for (size_t i = 0; i < mArraySize; ++i){
        ptr[i].~T();
    }
    delete[] mData;
}

template<typename T>
size_t Array<T>::size() const {
    return mArraySize;
}

template<typename T>
T &Array<T>::operator[](size_t i) {
    T *ptr = (T *) mData;
    return *(ptr + i);
}

template<typename T>
const T &Array<T>::operator[](size_t i) const {
    T *ptr = (T *) mData;
    return *(ptr + i);
}

template<typename T>
void Array<T>::mSwap(Array<T> &arr) {

    size_t t = mArraySize;
    mArraySize = arr.mArraySize;
    arr.mArraySize = t;

    byte *tmp = std::move(arr.mData);
    arr.mData = std::move(mData);
    mData = std::move(tmp);

//    mSwap(mArraySize, arr.mArraySize);
//    mSwap(mData, arr.mData);
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &arr) {
    if (this != &arr) {
        Array<T> temp(arr);
        temp.mSwap(*this);
    }
    return *this;
}

template<typename T>
Array<T>::Array(const Array &arr) {
    mArraySize = arr.mArraySize;
    mData = new byte[mArraySize * sizeof(T)];
    T *ptr = (T *) mData;
    for (size_t i = 0; i < mArraySize; ++i)
        new(ptr + i) T(arr[i]);
}

template<typename T>
void Array<T>::print() {
    for (size_t i = 0; i < size(); ++i)
        cout << *((T *) mData + i);
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


