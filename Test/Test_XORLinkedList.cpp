#include <iostream>
#include "XORLinkedList.hpp"
using namespace std;

template <typename T>
void printList(XORLinkedListHandler_LinkedList<T>* firstNode)
{
    XORLinkedListHandler_LinkedList<T> *prev_list = nullptr;
    XORLinkedListHandler_LinkedList<T> *next_list = nullptr;

    XORLinkedListHandler_LinkedList<T> *cur_list = firstNode;
    
    while(cur_list != nullptr)
    {
        cout << cur_list->data << " ";
        next_list = (XORLinkedListHandler_LinkedList<T>*)(((uintptr_t)prev_list) ^ ((uintptr_t)(cur_list->npXOR_list)));
        //next_list = XOR(prev_list, cur_list->npXOR_list);
        prev_list = cur_list;
        cur_list = next_list;
    }
    std::cout << endl;

}
int main()
{
    XORLinkedListHandler_LinkedList<int> *myFirstNode = nullptr;
    XORLinkedListHandler<int> myLinkList;

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

    return 0;
}