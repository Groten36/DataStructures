#include "Stack.h"

#include <iostream>
#include <stdexcept>
#include <algorithm>

Stack::Stack(int size) : top_(0), capacity_(size), stack_(nullptr) {
  if (size <= 0) {
    throw std::invalid_argument("Stack capacity must be positive");
  }
  stack_ = new int[capacity_];
}

Stack::Stack(const Stack &stack)
    : top_(stack.top_), capacity_(stack.capacity_), stack_(new int[capacity_]) {
  std::copy(stack.stack_, stack.stack_ + stack.top_, stack_);
}

Stack::Stack(Stack &&stack) noexcept
    : top_(stack.top_), capacity_(stack.capacity_), stack_(stack.stack_) {
  stack.stack_ = nullptr;
  stack.capacity_ = 0;
  stack.top_ = 0;
}

Stack::~Stack() { delete[] stack_; }

void Stack::resize(int newCapacity) {
  if (newCapacity < top_)
    throw std::out_of_range("New capacity smaller than size");
  int *resizedStack = new int[newCapacity];
  std::copy(stack_, stack_ + top_, resizedStack);
  delete[] stack_;
  stack_ = resizedStack;
  capacity_ = newCapacity;
}
void Stack::push(int value) {
  if (isFull())
    {
      resize(capacity_*2);
    }
  stack_[top_] = value;
  ++top_;
}

void Stack::pop() {
  if (empty())
    throw std::underflow_error("Empty stack");
  --top_;

  if(capacity_ > 4 && top_<capacity_/4){
    resize(capacity_/2);
  }
}

int Stack::peek() const {
  if (empty())
    throw std::underflow_error("Empty stack");
  return stack_[top_ - 1];
}

bool Stack::empty() const noexcept { return top_ == 0; }

bool Stack::isFull() const noexcept { return top_ == capacity_; }

int Stack::capacity() const noexcept { return capacity_; }

Stack &Stack::operator=(const Stack &stack) {
  if (this == &stack)
    return *this;

  int *newStack = new int[stack.capacity_];
  std::copy(stack.stack_, stack.stack_ + stack.top_, newStack);

  delete[] stack_;

  stack_ = newStack;
  capacity_ = stack.capacity_;
  top_ = stack.top_;

  return *this;
}

Stack &Stack::operator=(Stack &&stack) noexcept {
  if (this == &stack)
    return *this;

  delete[] stack_;

  stack_ = stack.stack_;
  capacity_ = stack.capacity_;
  top_ = stack.top_;

  stack.stack_ = nullptr;
  stack.capacity_ = 0;
  stack.top_ = 0;

  return *this;
}

void printStack(const Stack &stack) {
  for (int i = 0; i < stack.top_; i++) {
    std::cout << stack.stack_[i] << " ";
  }
}