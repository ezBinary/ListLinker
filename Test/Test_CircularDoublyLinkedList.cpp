#include <iostream>
#include "CircularDoublyLinkedList.hpp"

using namespace std;

template <class T>
void printList(CircularDoublyLinkedListHandler_LinkedList<T>* myFirstNode)
{
    CircularDoublyLinkedListHandler_LinkedList<T>* tempNode = myFirstNode;
    if (myFirstNode != nullptr) {
        do {
            cout << tempNode->data << " ";
            tempNode = tempNode->next_link;
        } while (tempNode != myFirstNode);
    }
    cout << endl;
}

int main()
{
    CircularDoublyLinkedListHandler_LinkedList<int> *myFirstNode = nullptr;
    CircularDoublyLinkedListHandler<int> myLinkList;

    myLinkList.PushData(&myFirstNode,1);
    myLinkList.PushData(&myFirstNode,2);
    myLinkList.PushData(&myFirstNode,3);
    myLinkList.PushData(&myFirstNode,4);
    myLinkList.PushData(&myFirstNode,5);

    printList(myFirstNode);

    myLinkList.PopData(&myFirstNode);
    myLinkList.PopData(&myFirstNode);

    printList(myFirstNode);

    myLinkList.AppendData(&myFirstNode,60);
    myLinkList.AppendData(&myFirstNode,70);
    myLinkList.AppendData(&myFirstNode,80);
    myLinkList.AppendData(&myFirstNode,90);

    printList(myFirstNode);

    myLinkList.RemoveLast(&myFirstNode);
    myLinkList.RemoveLast(&myFirstNode);
    myLinkList.RemoveLast(&myFirstNode);

    printList(myFirstNode);

    myLinkList.InsertData(&myFirstNode, 900, 1);
    myLinkList.InsertData(&myFirstNode, 800, 4);
    myLinkList.InsertData(&myFirstNode, 700, 3);
    myLinkList.InsertData(&myFirstNode, 600, 2);

    printList(myFirstNode);

    myLinkList.RemoveLast(&myFirstNode);
    myLinkList.PopData(&myFirstNode);

    printList(myFirstNode);

    return 0;
}