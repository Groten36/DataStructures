#include <iostream>

#include "DynamicArray.h"


int main() {
    DynamicArray arr=DynamicArray(10);
    for (int i=0;i<9;i++) {
        arr.push_back(1);
    }
    arr.print();
    std::cout<<"\n Nowa\n";
    arr.pushAtPosition(2,5);
    arr.print();
    std::cout<<"\n Nowa\n";
    arr.pop();
    arr.print();
    return 0;
}