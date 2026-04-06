#include <iostream>
#include <string>

#include "DynamicArray.h"
#include "Stack.h"

bool isOpeningBracket(const char c){
  return c=='('||c=='['||c=='{';
}

bool isClosingBracket(const char c){
  return c==')'||c==']'||c=='}';
}

bool isMatching(const char o, const char c){
  return (o=='('&&c==')')||(o=='['&&c==']')||(o=='{'&&c=='}');
}

int main() {
  constexpr std::size_t kBitCapacity = 32;
  Stack bitStack(kBitCapacity);
  unsigned int number=11;
  if (number == 0) {
    std::cout << 0 << '\n';
    return 0;
}

  while(number!=0){
    bitStack.push(number%2);
    number=number/2;
  }

  printStack(bitStack);

}