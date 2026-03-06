//
// Created by vader on 27/02/2026.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H



class DynamicArray {
    unsigned int capacity;
    unsigned int size;
    int* array;
public:
void push_back(int element);
    void pop();
    void resizeArray(int newSize);
    int getSize();
    int getCapacity();
    bool isEmpty();
    void pushAtPosition(int element,int position);
    void removeAtPosition(int position);
    void removeByValueFirst(int value);
    void removeByValueAll(int value);
    int find(int value);
    void print();

    DynamicArray();
    DynamicArray(int size);
    DynamicArray(const DynamicArray& arr);
    DynamicArray(DynamicArray&& arr) noexcept;
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& arr);
    DynamicArray& operator=(DynamicArray&& arr) noexcept;
    DynamicArray operator[](int index);


};



#endif //DYNAMICARRAY_H
