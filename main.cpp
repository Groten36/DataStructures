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
  bool correct=true;
  std::string brackets="{[(]}";
  Stack stack(brackets.length());
  for(auto s:brackets){
    if(isOpeningBracket(s)){
      stack.push(s);
    }else
      if(isClosingBracket(s)){
        if(!stack.empty()&&isMatching(stack.peek(),s)){
      stack.pop();}
      else{
        correct=false;
      }
    }
  }
   if (correct) {
    std::cout << "Brackets correct\n";
  } else {
    std::cout << "Wrong brackets\n";
  }

}