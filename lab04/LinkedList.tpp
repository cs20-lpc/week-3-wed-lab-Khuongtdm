

#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    // TODO
     Node* newNode = new Node(elem);

    if (head == nullptr)
    {
        head = newNode;
        this->length++;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    this->length++;
    
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
    Node* curr = head;
    if (curr == nullptr)
        return;
    Node* previous = head;
    while (curr != nullptr)
    {
        curr = curr->next;
        delete previous;
        previous = curr;
    }
    head = nullptr;
    this->length =0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
    //do some checking
    if (position < 0 || position >= this->length)
        throw out_of_range("Index out of range");
    Node* curr = head;
    for(int i =0; i<position;i++)
    {
        curr = curr->next;
    }
    if (curr == nullptr)
        throw string("head ptr is null");
    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
    //again, we need some checking
    if (position < 0 || position >= this->length)
        throw out_of_range("Index out of range");
    Node* curr = head;
    for(int i =0; i<position;i++)
    {
        curr = curr->next;
    }
    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
