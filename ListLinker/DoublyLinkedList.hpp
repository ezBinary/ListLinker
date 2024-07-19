#pragma once

template <typename T>

struct DoublyLinkedListHandler_LinkedList
{
    DoublyLinkedListHandler_LinkedList* prev_link = nullptr;
    T data;
    DoublyLinkedListHandler_LinkedList* next_link = nullptr;
};

template <typename T> class DoublyLinkedListHandler
{
private:
    using Node = DoublyLinkedListHandler_LinkedList<T>;
    Node* firstNode = nullptr;

    void deleteLinkedList(Node** start)
    {
        Node* nextNode, * current = *start;
        while (current != nullptr)
        {
            nextNode = current->next_link;
            delete current;
            current = nextNode;
        }
        *start = nullptr;
    }
public:
    
    void PushData(Node** start, T value)
    {
        Node* new_node = new Node();

        new_node->data = value;
        new_node->next_link = (*start);
        new_node->prev_link = nullptr;

        if ((*start) != nullptr)
        {
            (*start)->prev_link = new_node;
        }
        (*start) = new_node;
        firstNode = *start;
    }
    void AppendData(Node** start, T value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next_link = nullptr;

        if ((*start) == nullptr)
        {
            (*start) = newNode;
            firstNode = *start;
            newNode->prev_link = nullptr;
            return;
        }

        Node* tempNode = *start;
        while (tempNode->next_link != nullptr)
        {
            tempNode = tempNode->next_link;
        }
        tempNode->next_link = newNode;
        newNode->prev_link = tempNode;
    }
    
    void InsertData(Node** start, T value, int position)
    {
        unsigned int counter;
        counter = 0;
        Node* newNode = nullptr, * tempNode = nullptr, * prevNode = nullptr;
        newNode = new (Node);
        newNode->data = value;
        newNode->next_link = nullptr;
        newNode->prev_link = nullptr;

        tempNode = (*start);
        while (tempNode != nullptr)
        {
            tempNode = tempNode->next_link;
            counter++;
        }

        if (position == 1)
        {
            if (*start == nullptr)
            {
                *start = newNode;
                (*start)->next_link = nullptr;
            }
            else
            {
                prevNode = (*start);

                *start = newNode;
                (*start)->next_link = prevNode;
                (*start)->prev_link = nullptr;
                prevNode->prev_link = *start;
            }
        }
        else if (position > 1 && position <= counter)
        {
            tempNode = (*start);
            for (int i = 1; i < position; i++)
            {
                prevNode = tempNode;
                tempNode = tempNode->next_link;
            }
            prevNode->next_link = newNode;
            newNode->next_link = tempNode;
            newNode->prev_link = prevNode;
            tempNode->prev_link = newNode;
        }
        else
        {
            delete newNode;
        }
        firstNode = *start;
    }

    void PopData(Node** start)
    {
        if (*start != nullptr) 
        {
            Node* delNode = *start;
            *start = delNode->next_link;
            (*start)->prev_link = nullptr;
            delete delNode;
        }
        firstNode = *start;
    }
    void RemoveLast(Node** start)
    {
        if (*start == nullptr) {
            return;													// List is empty
        }
        if ((*start)->next_link == nullptr) {
            delete* start;
            *start = nullptr;										// List has only one node
        }
        else {
            Node* tempNode = *start;
            while (tempNode->next_link->next_link != nullptr) {
                tempNode = tempNode->next_link;
            }
            delete tempNode->next_link;
            tempNode->next_link = nullptr;
        }
        firstNode = *start;
    }

    ~DoublyLinkedListHandler()
    {
        deleteLinkedList(&firstNode);
    }
};