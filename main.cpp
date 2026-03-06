#include <iostream>

#include "DynamicArray.h"


int main() {

    DynamicArray arr;
    int choice, value, pos;

    do {
        std::cout << "\n1 Push Back\n2 Insert at position\n3 Remove\n4 Find\n5 Print\n6 Exit\n";
        std::cin >> choice;

        switch(choice) {

            case 1:
                std::cout<<"Value: ";
                std::cin>>value;
                arr.push_back(value);
                break;

            case 2:
                std::cout<<"Value: ";
                std::cin>>value;
                std::cout<<"Position: ";
                std::cin>>pos;
                arr.pushAtPosition(value,pos);
                break;

            case 3:
                std::cout<<"Position: ";
                std::cin>>pos;
                arr.removeAtPosition(pos);
                break;

            case 4:
                std::cout<<"Value: ";
                std::cin>>value;
                std::cout<<"Index: "<<arr.find(value)<<std::endl;
                break;

            case 5:
                arr.print();
                break;
        }

    } while(choice != 6);
    return 0;
}