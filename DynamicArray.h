//
// Created by vader on 27/02/2026.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H



class DynamicArray {
    int capacity;
    int size;
    int* array;
public:
void push_back(int element);
    void pop();
    void resizeArray(int newCapacity);
    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;
    void pushAtPosition(int element,int position);
    void removeAtPosition(int position);
    void removeByValueFirst(int value);
    void removeByValueAll(int value);
    int find(int value) const;
    void print() const;

    DynamicArray();
    DynamicArray(int capacity);
    DynamicArray(const DynamicArray& arr);
    DynamicArray(DynamicArray&& arr) noexcept;
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& arr);
    DynamicArray& operator=(DynamicArray&& arr) noexcept;
    int& operator[](size_t index);
    const int& operator[](size_t index) const;


};



#endif //DYNAMICARRAY_H
