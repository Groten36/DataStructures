//
// Created by vader on 27/02/2026.
//

#include "DynamicArray.h"
DynamicArray::DynamicArray(int size) {
    this->capacity=size;
    this->size=size;
    this->array=new int[size];
}

DynamicArray::DynamicArray(const DynamicArray& arr) {
    this->capacity=arr.capacity;
    this->size=arr.size;
    this->array=new int[arr.capacity];
    for (int i=0;i<capacity;i++) {
        this->array[i]=arr.array[i];
    }

}

DynamicArray::DynamicArray(DynamicArray&& arr) {
    capacity=arr.capacity;
    size=arr.size;
    array=arr.array;
    arr.array=nullptr;
    arr.capacity=0;
    arr.size=0;
}
DynamicArray::~DynamicArray() {
    delete[] array;
}

DynamicArray DynamicArray::operator=(DynamicArray& arr) {
    if (this==&arr) return *this;
    delete[] array;
    capacity=arr.capacity;
    size=arr.size;
    array=new int[capacity];
    for (int i=0;i<capacity;i++) {
        array[i]=arr.array[i];
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& arr) {
    if (this==&arr) return *this;
    delete[] array;
    capacity=arr.capacity;
    size=arr.size;
    array=arr.array;
    arr.array=nullptr;
    arr.capacity=0;
    arr.size=0;
    return *this;
}