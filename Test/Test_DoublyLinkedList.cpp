#include "DoublyLinkedList.hpp"
#include <iostream>

using namespace std;

template <typename T>
void printList(DoublyLinkedListHandler_LinkedList<T>* myFirstNode)
{
    DoublyLinkedListHandler_LinkedList<T>* temp = myFirstNode;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next_link;
    }
    std::cout << std::endl;
}
template <typename T>
void printList_Reverse(DoublyLinkedListHandler_LinkedList<T>* myFirstNode)
{
    DoublyLinkedListHandler_LinkedList<T>* temp = myFirstNode;
    while (temp->next_link != nullptr)
    {
        temp = temp->next_link;
    }
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->prev_link;
    }
    std::cout << std::endl;
}
int main()
{
    DoublyLinkedListHandler_LinkedList<int>* myFirstNode = nullptr;     // create a pointer to the first node
    DoublyLinkedListHandler<int> myLinkList;                            // create an object to work with singly linkedlist
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
    printList_Reverse(myFirstNode);
    return 0;
}