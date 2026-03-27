#include <iostream>

#include "DynamicArray.h"
#include "Stack.h"

int main() {

  Stack s(5);

  // Push elements
  s.push(10);
  s.push(20);
  s.push(30);

  std::cout << "Size: " << s.capacity() << "\n"; // 3
  std::cout << "Top:  " << s.peek() << "\n";     // 30

  // Pop and print all
  while (!s.empty()) {
    std::cout << s.peek() << " ";
    s.pop();
  }
  std::cout << "\n"; // 30 20 10

  return 0;
}