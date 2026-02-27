//
// Created by vader on 27/02/2026.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H



class DynamicArray {
    int capacity;
    int* arr;

void push_back(int element);
    void pop(int element);
    void resizeArray(int newSize);
    int getSize();
    int getCapacity();
    bool isEmpty();
    void pushAtPosition(int element,int position);
    void removeAtPosition(int element,int position);
    void removeByValueFirst(int value);
    void removeByValueAll(int value);
    int find(int value);
    int print();

    DynamicArray();
    DynamicArray(const DynamicArray& arr);
    DynamicArray(DynamicArray&& arr);
    ~DynamicArray();

    DynamicArray operator=(DynamicArray& arr);


};



#endif //DYNAMICARRAY_H
