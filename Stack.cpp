#include "Stack.h"

#include <iostream>
#include <stdexcept>

Stack::Stack(int size) : top_(0), capacity_(size), stack_(nullptr) {
  if (size <= 0) {
    throw std::invalid_argument("Stack capacity must be positive");
  }
  stack_ = new int[capacity_];
}

Stack::Stack(const Stack &stack)
    : top_(stack.top_), capacity_(stack.capacity_), stack_(nullptr) {
  stack_ = new int[capacity_];
  for (int i = 0; i < top_; i++) {
    stack_[i] = stack.stack_[i];
  }
}

Stack::Stack(Stack &&stack) noexcept
    : top_(stack.top_), capacity_(stack.capacity_), stack_(stack.stack_) {
  stack.stack_ = nullptr;
  stack.capacity_ = 0;
  stack.top_ = 0;
}

Stack::~Stack() { delete[] stack_; }

void Stack::push(int value) {
  if (isFull())
    throw std::overflow_error("Stack is full");
  stack_[top_] = value;
  ++top_;
}

void Stack::pop() {
  if (empty())
    throw std::underflow_error("Empty stack");
  --top_;
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
  for (int i = 0; i < stack.top_; i++) {
    newStack[i] = stack.stack_[i];
  }

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