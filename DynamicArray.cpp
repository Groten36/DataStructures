//
// Created by vader on 27/02/2026.
//
#include<iostream>

#include "DynamicArray.h"
DynamicArray::DynamicArray() :capacity(0),size(0),array(nullptr){};

DynamicArray::DynamicArray(int capacity) {
    this->capacity=capacity;
    this->size=0;
    this->array= capacity>0 ? new int[capacity]:nullptr;
}

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

DynamicArray DynamicArray::operator[](int index) {
    if (index<0 || index>=size) throw std::out_of_range("Index out of range");
    return array[index];
}

void DynamicArray::print() {
    if (array!=nullptr) {
        for (int i=0;i<size;i++) {
            std::cout<<array[i];
        }
    }
}

void DynamicArray::push_back(int element) {
    if (size>=capacity) resizeArray(capacity==0 ? 1 : capacity*2);
    array[size]=element;
    size++;
}

void DynamicArray::resizeArray(int newSize) {
    if (newSize<=size) return; //temporary check; shrinking array will be implement later;
    int* resizedArray=new int[newSize];
    for (int i=0;i<size;i++) {
        resizedArray[i]=array[i];
    }
    delete[] array;
    array=resizedArray;
    capacity=newSize;

    //for later add handling situation when new capacity is smaller than current size
}

int DynamicArray::getCapacity() {
    return capacity;
}

int DynamicArray::getSize() {
    return size;
}

bool DynamicArray::isEmpty() {
    return size==0;
}

int DynamicArray::find(int value) {
    for (int i=0;i<size;i++) {
        if (array[i]==value) return i;
    }
    return -1;
}

void DynamicArray::pushAtPosition(int element, int position) {
    if (size>=capacity) resizeArray(capacity==0 ? 1:capacity*2);
    if (position>= size || position<0) throw std::out_of_range("Index out of range");

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
    //TBA: capacity shrinking
}

void DynamicArray::removeAtPosition(int position) {
    if (this->isEmpty()) {

        throw std::underflow_error("Empty array");
    }
    if (position<0 || position>size-1) return;
    for (int i=position;i<size-1;i++) {
        array[i]=array[i+1];
    }
    size--;
}








