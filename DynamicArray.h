//
// Created by vader on 27/02/2026.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
  size_t capacity_;
  size_t size_;
  int *array_;

  void resizeArray(size_t newCapacity);

public:
  void push_back(int element);
  void pop();
  size_t size() const noexcept;
  size_t capacity() const noexcept;
  bool empty() const noexcept;
  void insert(int element, size_t position);
  void erase(size_t position);
  size_t find(int value) const;
  void print() const;
  void clear() noexcept;

  DynamicArray();
  DynamicArray(size_t capacity);
  DynamicArray(const DynamicArray &arr);
  DynamicArray(DynamicArray &&arr) noexcept;
  ~DynamicArray();

  DynamicArray &operator=(const DynamicArray &arr);
  DynamicArray &operator=(DynamicArray &&arr) noexcept;
  int &operator[](size_t index);
  const int &operator[](size_t index) const;

  int *begin() noexcept;
  int *end() noexcept;
  const int *begin() const noexcept;
  const int *end() const noexcept;
  int &front();
  int &back();
  const int &front() const;
  const int &back() const;
};

#endif // DYNAMICARRAY_H
