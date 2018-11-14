//
// Created by Computer on 14.11.2018.
//

#ifndef HW_TEMPLATES_ARRAY_H
#define HW_TEMPLATES_ARRAY_H


#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;

typedef unsigned char byte;

template<typename T>
class Array {

public:

    explicit Array(size_t size = 0, const T &value = T());

    Array(const Array &);

    ~Array();

    Array &operator=(const Array<T> &);

    size_t size() const;

    T &operator[](size_t);

    const T &operator[](size_t) const;

    void print();

private:

    size_t _size;
    byte *data;

//    T *data;
    void swap(Array<T> &arr);
};


#endif //HW_TEMPLATES_ARRAY_H
