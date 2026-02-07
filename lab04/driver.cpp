// TO DO: Implement the driver main() function to test your code.

#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main() {
    LinkedList<int> list;
    cout << "List before append: " << list;
    //add element
    list.append(10);
    list.append(20);
    list.append(30);
    cout << "List after append: " << list;
    cout << "Length: " << list.getLength() << endl;

    // Access elements
    cout << "Element at index 0: " << list.getElement(0) << endl;
    cout << "Element at index 1: " << list.getElement(1) << endl;
    cout << "Element at index 2: " << list.getElement(2) << endl;

    // Replace
    list.replace(1, 99);
    cout << "After replace index 1 with 99: " << list;

    // Clear
    list.clear();
    cout << "After clear: " << list;
    cout << "Length after clear: " << list.getLength() << endl;
    cout << "Empty after clear? " << list.isEmpty() << endl;

    // some edge cases
    
    //empty list test
    cout << "----------------------------------------------------------------------\n";
    cout << "Empty test" << endl;
    LinkedList<int> list1;
    cout << "Current list: " << list1;
    cout << "Is empty? " << list1.isEmpty() << endl;
    cout << "Length: " << list1.getLength() << endl;
    try {
        list.getElement(0);
    }
    catch (const exception& e) {
        cout << "Bug: " << e.what() << endl;
    }

    //head case check
    cout << "----------------------------------------------------------------------\n";
    cout << "Head case check" << endl;
    LinkedList<int> list2;
    list2.append(10);
    cout << "Current list: " << list2;
    cout << list2;
    cout << "Length: " << list2.getLength() << endl;
    cout << "Head element: " << list2.getElement(0) << endl;

    //Replace check
    cout << "----------------------------------------------------------------------\n";
    cout << "Replace check" << endl;
    LinkedList<int> list3;
    list3.append(20);
    list3.append(30);
    list3.append(40);
    list3.append(10);
    cout << "Current list: " << list3;
    //replace head
    list3.replace(0, 99);
    cout << "After replacing head: " << list3;

    // replace last
    list3.replace(list3.getLength() - 1, 77);
    cout << "After replacing tail: " << list3;

    // invalid index
    try {
        list3.replace(100, 5);
    }
    catch (const exception& e) {
        cout << "Bug: " << e.what() << endl;
        
    }


    //GetElement test
    cout << "----------------------------------------------------------------------\n";
    cout << "Get Element Boundaries" << endl;
    LinkedList<int> list4;
    list4.append(99);
    list4.append(99);
    list4.append(99);
    list4.append(99);
    cout << "Current list: " << list4;
    cout << "First: " << list4.getElement(0) << endl;
    cout << "Last: " << list4.getElement(list4.getLength() - 1) << endl;

    try {
        list4.getElement(-1);
    }
    catch (const exception& e) {
        cout << "(negative index): " << e.what() << endl;
    }

    try {
        list4.getElement(list4.getLength());
    }
    catch (const exception& e) {
        cout << "(index == length): " << e.what() << endl;
    }
}

