#include "CircularLinkedList.hpp"
#include <iostream>
using namespace std;

template <class T>
void printList(CircularLinkedListHandler_LinkedList<T>* myFirstNode)
{
    CircularLinkedListHandler_LinkedList<T>* tempNode = myFirstNode;
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
    CircularLinkedListHandler_LinkedList<int>* Node = nullptr;
    CircularLinkedListHandler<int> myLinkList;

    myLinkList.PushData(&Node, 1);
    myLinkList.PushData(&Node, 2);
    myLinkList.PushData(&Node, 3);
    myLinkList.PushData(&Node, 4);
    myLinkList.PushData(&Node, 5);

    printList(Node);

    myLinkList.PopData(&Node);
    myLinkList.PopData(&Node);

    printList(Node);
    
    myLinkList.AppendData(&Node, 60);
    myLinkList.AppendData(&Node, 70);
    myLinkList.AppendData(&Node, 80);

    printList(Node);

    myLinkList.RemoveLast(&Node);
    myLinkList.RemoveLast(&Node);
    myLinkList.RemoveLast(&Node);

    printList(Node);

    myLinkList.InsertData(&Node, 900, 1);
    myLinkList.InsertData(&Node, 800, 4);
    myLinkList.InsertData(&Node, 700, 3);
    myLinkList.InsertData(&Node, 600, 2);

    myLinkList.RemoveLast(&Node);
    myLinkList.PopData(&Node);

    printList(Node);

    myLinkList.AppendData(&Node, 1000);
    myLinkList.AppendData(&Node, 2000);
    myLinkList.PopData(&Node);
    
    printList(Node);

	return 0;
}