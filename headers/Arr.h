#pragma once

#include <exception>
#include <iostream>
#include <vector>

template <typename T, size_t Nv, size_t Mv>
struct Arr
{
    T v[Nv][Mv]{};

    void init(size_t N, size_t M);
    T* operator[](size_t index);
    Arr& operator=(const Arr& b);
};

template <typename T>
struct Arr<T, 0, 0>
{
    std::vector<std::vector<T>> v;

    void init(size_t N, size_t M);
    std::vector<T>& operator[](size_t index);
    Arr& operator=(const Arr& b);
};

template <typename T, size_t Nv, size_t Mv>
void Arr<T, Nv, Mv>::init(size_t N, size_t M) {
    if (N != Nv || M != Mv) {std::cout << "Wrong size of field\n"; throw std::exception();}
}

template <typename T>
void Arr<T, 0, 0>::init(size_t N, size_t M) {
    v.resize(N, std::vector<T>(M));
}

template <typename T, size_t Nv, size_t Mv>
T* Arr<T, Nv, Mv>::operator[](size_t index) {
    return v[index];
}

template <typename T>
std::vector<T>& Arr<T, 0, 0>::operator[](size_t index) {
    return v[index];
}

template <typename T, size_t Nv, size_t Mv>
Arr<T, Nv, Mv>& Arr<T, Nv, Mv>::operator=(const Arr& other)
{
    if(this == &other) {return *this;}
    memcpy(v, other.v, sizeof(v));
    return *this;
}

template <typename T>
Arr<T, 0, 0>& Arr<T, 0, 0>::operator=(const Arr& other)
{
    v = other.v;
    return *this;
}