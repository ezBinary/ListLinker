#include "SinglyLinkedList.hpp"
#include <iostream>

using namespace std;

template <typename T>
void printList(SinglyLinkedListHandler_LinkedList<T>* myFirstNode)
{
    SinglyLinkedListHandler_LinkedList<T>* temp = myFirstNode;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next_link;
    }
    std::cout << std::endl;
}


int main()
{
    SinglyLinkedListHandler_LinkedList<int> *myFirstNode = nullptr;     // create a pointer to the first node
    SinglyLinkedListHandler<int> myLinkList;                            // create an object to work with singly linkedlist
    myLinkList.PushData(&myFirstNode, 1);
    myLinkList.PushData(&myFirstNode, 2);
    myLinkList.PushData(&myFirstNode, 3);
    myLinkList.PushData(&myFirstNode, 4);
    myLinkList.PushData(&myFirstNode, 5);
    printList(myFirstNode);

    myLinkList.AppendData(&myFirstNode, 6);
    myLinkList.AppendData(&myFirstNode, 7);
    myLinkList.AppendData(&myFirstNode, 8);

    printList(myFirstNode);
    
    myLinkList.InsertData(&myFirstNode, 90, 1);
    myLinkList.InsertData(&myFirstNode, 80, 2);
    myLinkList.InsertData(&myFirstNode, 70, 3);

    printList(myFirstNode);

    myLinkList.PopData(&myFirstNode);
    myLinkList.PopData(&myFirstNode);

    printList(myFirstNode);

    myLinkList.RemoveLast(&myFirstNode);
    myLinkList.RemoveLast(&myFirstNode);

    printList(myFirstNode);

}
