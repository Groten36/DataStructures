//
// Created by vader on 27/02/2026.
//
#include<iostream>
#include <stdexcept>
#include <algorithm>


#include "DynamicArray.h"
DynamicArray::DynamicArray() :capacity_(0),size_(0),array_(nullptr){};

DynamicArray::DynamicArray(size_t capacity):capacity_(capacity),size_(0),array_(capacity>0?new int[capacity]:nullptr){};


DynamicArray::DynamicArray(const DynamicArray& arr) {
    capacity_=arr.capacity_;
    size_=arr.size_;
    if (capacity_>0) {
        this->array_=new int[arr.capacity_];
        std::copy(arr.array_,arr.array_+size_,array_);
    }
    else{array_=nullptr;}

}

DynamicArray::DynamicArray(DynamicArray&& arr) noexcept{
    capacity_=arr.capacity_;
    size_=arr.size_;
    array_=arr.array_;
    arr.array_=nullptr;
    arr.capacity_=0;
    arr.size_=0;
}
DynamicArray::~DynamicArray() {
    delete[] array_;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& arr) {
    if (this==&arr) return *this;
    delete[] array_;
    capacity_=arr.capacity_;
    size_=arr.size_;
    if (capacity_>0) {
        array_=new int[capacity_];
        std::copy(arr.array_,arr.array_+size_,array_);
    }else{array_=nullptr;}
    return *this;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& arr) noexcept {
    if (this==&arr) return *this;
    delete[] array_;
    capacity_=arr.capacity_;
    size_=arr.size_;
    array_=arr.array_;
    arr.array_=nullptr;
    arr.capacity_=0;
    arr.size_=0;
    return *this;
}
int& DynamicArray::operator[](size_t index) {
    if (index>=size_) throw std::out_of_range("Index out of range");
    return array_[index];
}

const int& DynamicArray::operator[](size_t index) const{
    if (index>=size_) throw std::out_of_range("Index out of range");
    return array_[index];
}

void DynamicArray::print() const{
    for (size_t i=0;i<size_;i++) {
        std::cout<<array_[i]<<" ";
        }

}

void DynamicArray::push_back(int element) {
    if (size_>=capacity_) resizeArray(capacity_==0 ? 1 : capacity_*2);
    array_[size_++]=element;
}

void DynamicArray::resizeArray(size_t newCapacity) {
    if (newCapacity<size_) throw std::out_of_range("New capacity smaller than size");
    int* resizedArray=new int[newCapacity];
    std::copy(array_,array_+size_,resizedArray);
    delete[] array_;
    array_=resizedArray;
    capacity_=newCapacity;

}

size_t DynamicArray::capacity() const noexcept{
    return capacity_;
}

size_t DynamicArray::size() const noexcept{
    return size_;
}

bool DynamicArray::empty() const noexcept{
    return size_==0;
}

size_t DynamicArray::find(int value) const{
    for (size_t i=0;i<size_;i++) {
        if (array_[i]==value) return i;
    }
    return -1;
}

void DynamicArray::insert(int element, size_t position) {
    if (position> size_ ) throw std::out_of_range("Index out of range");
    if (size_>=capacity_) resizeArray(capacity_==0 ? 1:capacity_*2);

    for (size_t i=size_;i>position;--i) {
        array_[i]=array_[i-1];
    }
    array_[position]=element;
    size_++;
}

void DynamicArray::pop() {
    if (this->empty()) {

        throw std::underflow_error("Empty array");
    }
    size_--;
    if (capacity_>1&&size_<capacity_/4) resizeArray(capacity_/2);
}

void DynamicArray::erase(size_t position) {
    if (this->empty()) {

        throw std::underflow_error("Empty array");
    }
    if (position>=size_) throw std::out_of_range("Index out of range");
    for (size_t i=position;i<size_-1;i++) {
        array_[i]=array_[i+1];
    }
    size_--;
}

void DynamicArray::clear() {
    size_=0;
}

int* DynamicArray::begin() noexcept {
    return array_;
}

int* DynamicArray::end() noexcept {
    return array_+size_;
}

const int* DynamicArray::begin() const noexcept{
    return array_;
}
const int* DynamicArray::end() const noexcept{
    return array_+size_;
}

int& DynamicArray::front() {
    if (empty())
        throw std::out_of_range("Empty array");
    return *array_;
}

int& DynamicArray::back() {
    if (empty())
        throw std::out_of_range("Empty array");
    return *(array_+size_-1);
}

const int& DynamicArray::front() const {
    if (empty())
        throw std::out_of_range("Empty array");
    return *array_;
}

const int& DynamicArray::back() const {
    if (empty())
        throw std::out_of_range("Empty array");
    return *(array_+size_-1);
}







