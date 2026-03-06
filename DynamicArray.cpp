//
// Created by vader on 27/02/2026.
//
#include<iostream>
#include <stdexcept>

#include "DynamicArray.h"
DynamicArray::DynamicArray() :capacity(0),size(0),array(nullptr){};

DynamicArray::DynamicArray(int capacity):capacity(capacity),size(0),array(capacity>0?new int[capacity]:nullptr){};


DynamicArray::DynamicArray(const DynamicArray& arr) {
    this->capacity=arr.capacity;
    this->size=arr.size;
    this->array=new int[arr.capacity];
    for (int i=0;i<size;i++) {
        this->array[i]=arr.array[i];
    }

}

DynamicArray::DynamicArray(DynamicArray&& arr) noexcept{
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

DynamicArray& DynamicArray::operator=(const DynamicArray& arr) {
    if (this==&arr) return *this;
    delete[] array;
    capacity=arr.capacity;
    size=arr.size;
    array=new int[capacity];
    for (int i=0;i<size;i++) {
        array[i]=arr.array[i];
    }
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& arr) noexcept {
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
int& DynamicArray::operator[](size_t index) {
    if (index>=size) throw std::out_of_range("Index out of range");
    return array[index];
}

const int& DynamicArray::operator[](size_t index) const{
    if (index>=size) throw std::out_of_range("Index out of range");
    return array[index];
}

void DynamicArray::print() const{
    for (int i=0;i<size;i++) {
        std::cout<<array[i]<<" ";
        }

}

void DynamicArray::push_back(int element) {
    if (size>=capacity) resizeArray(capacity==0 ? 1 : capacity*2);
    array[size++]=element;
}

void DynamicArray::resizeArray(int newCapacity) {
    if (newCapacity<size) throw std::out_of_range("New capacity smaller than size");
    int* resizedArray=new int[newCapacity];
    for (int i=0;i<size;i++) {
        resizedArray[i]=array[i];
    }
    delete[] array;
    array=resizedArray;
    capacity=newCapacity;

}

int DynamicArray::getCapacity() const {
    return capacity;
}

int DynamicArray::getSize() const{
    return size;
}

bool DynamicArray::isEmpty() const{
    return size==0;
}

int DynamicArray::find(int value) const{
    for (int i=0;i<size;i++) {
        if (array[i]==value) return i;
    }
    return -1;
}

void DynamicArray::pushAtPosition(int element, int position) {
    if (position> size || position<0) throw std::out_of_range("Index out of range");
    if (size>=capacity) resizeArray(capacity==0 ? 1:capacity*2);

    for (int i=size;i>position;i--) {
        array[i]=array[i-1];
    }
    array[position]=element;
    size++;
}

void DynamicArray::pop() {
    if (this->isEmpty()) {

        throw std::underflow_error("Empty array");
    }
    size--;
    if (size<capacity/4) resizeArray(capacity/2);
}

void DynamicArray::removeAtPosition(int position) {
    if (this->isEmpty()) {

        throw std::underflow_error("Empty array");
    }
    if (position<0 || position>=size) return;
    for (int i=position;i<size-1;i++) {
        array[i]=array[i+1];
    }
    size--;
}








